#ifdef WIN32
#include <windows.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "point.h"
#include <map>
#include <fstream>
#include "fileHandler.h"
#include "algorithms.h"
#include "server.h"
#define END '\u0003'

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc <= 3) {
        return 0;
    }
    int k = stoi(argv[2]);
    Server server(5555, k, Point::EUCLIDEAN);
    server.loadClassified(argv[1]);
    server.run();
    return 0;
}


Server::Server(int port, int k, Point::DistanceMetric metric) {
    this->k = k;
    this->metric = metric;
    const int server_port = port;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    this->sock = sock;
}

Server::~Server() {
    close(sock);
}

int Server::getSock() {
    return sock;
}

int Server::acceptClient() {
    struct sockaddr_in clientSin;
    #ifdef WIN32
    int addrLen = sizeof(clientSin);
    #else
    unsigned int addrLen = sizeof(clientSin);
    #endif
    int clientSock = accept(sock,  (struct sockaddr *) &clientSin,  &addrLen);

    if (clientSock < 0) {
        perror("error accepting client");
    }

    return clientSock;
}

void Server::sendToClient(int clientSock, const char* buffer, int bufferSize) {
    int sentBytes = send(clientSock, buffer, bufferSize, 0);
    if (sentBytes < 0) {
        perror("error sending to client");
    }
}

bool Server::receiveFromClient(int clientSock, char* buffer, int bufferSize) {
    int readBytes = recv(clientSock, buffer, bufferSize, 0);
    if (readBytes < 0) {
        perror("error reading from client");
    }
    return buffer[0] != END;
}

void Server::loadClassified(string fileName) {
    points = decryptClassifiedFile(fileName);
}

void Server::run() {
    char buffer[4096];
    int clientSock = acceptClient();
    int expectedDataLen = sizeof(buffer);
    while (receiveFromClient(clientSock, buffer, expectedDataLen)) {
        Point p(buffer);
        string ans = classify(p, this->points, Point::EUCLIDEAN, 3);
        sendToClient(clientSock, ans.c_str(), ans.length());
    }
    close(clientSock);
}
