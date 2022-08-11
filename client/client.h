#include <string>
#include <fstream>

#define ERROR -1
#define SUCCESS 0
#define END '\u0003'

class Client {
    private:
    int sendLine(std::string line, int socket);
    int getLine(int socket, char* buffer, int bufferSize);
    int writeLine(std::string line, std::ofstream outputStream);

    public:
    static const int DEFAULT_BUFFER_SIZE = 4096;
    int sendFile(std::string filePath, int socket);
    int writeFileFromSocket(int socket, std::string filePath);
};