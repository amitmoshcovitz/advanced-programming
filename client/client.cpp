#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <client.h>


using namespace std;


int Client::sendLine(std::string line, int socket) {
    int sent_bytes = send(socket, line, line.size(), 0);
    if (sent_bytes < 0) {
        return ERROR;
    }
}

int Client::sendFile(std::string filePath, int socket) {
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        int sent = sendLine(line, socket);
        if (sent < 0) {
            file.close();
            return sent;
        }
    }
    int sent_bytes = send(socket, {END}, sizeof(END), 0);
    if (sent_bytes < 0) {
        file.close();
        return ERROR;
    }
    file.close();
    return SUCCESS;
}

int Client::writeLine(std::string line, std::ofstream outputStream) {
    outputStream << line << std::endl;
}

int Client::getLine(int socket, char* buffer, int bufferSize) {
    int read_bytes = recv(socket, buffer, bufferSize, 0);
    return read_bytes;
}

int Client::writeFileFromSocket(int socket, std::string filePath) {
    ofstream file(filePath);

    char buffer[Client::DEFAULT_BUFFER_SIZE];
    int bufferSize = Client::DEFAULT_BUFFER_SIZE;
    do {
        int result = Client::getLine(socket, buffer, bufferSize);
        if (result < 0) {
            file.close();
            return ERROR;
        }        
        file << buffer << std::endl;
    } while(buffer[0] != END);

    return SUCCESS;
}




int main(int argc, char const *argv[]) {

    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    Client user;
    user.sendFile(argv[1], sock);
    user.writeFileFromSocket(sock, argv[2]);

    close(sock);

    return 0;
}