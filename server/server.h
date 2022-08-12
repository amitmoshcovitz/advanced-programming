#ifdef WIN32
#include <windows.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#include <map>
#include "../point.h"
#include <fstream>

class Server {
    private:
    int sock;
    map<Point, string> points;
    int k;
    Point::DistanceMetric metric;

    public:
    Server(int port, int k, Point::DistanceMetric metric);

    ~Server();

    int getSock();

    void run();

    void loadClassified(string fileName);

    private:
    int acceptClient();

    void sendToClient(int clientSock, const char* buffer, int bufferSize);

    bool receiveFromClient(int clientSock, char* buffer, int bufferSize);
};