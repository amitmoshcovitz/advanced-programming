#include <vector>
#include <fstream>
#include <map>
#include "point.h"
#include "fileHandler.h"

using namespace std;

map<Point*, std::string>* decryptClassifiedFile(std::string fileName) {
    map<Point*, std::string>* decryptedFile = new map<Point*, std::string>();
    ifstream file(fileName);
    std::string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        int seperatorIndex = line.find_last_of(",");
        (*decryptedFile)[new Point(line.substr(0, seperatorIndex))] = line.substr(seperatorIndex + 1);
    }
    file.close();
    return decryptedFile;
}

vector<Point*>* decryptUnclassifiedFile(std::string fileName) {
    vector<Point*>* decryptedFile = new vector<Point*>();
    ifstream file(fileName);
    std::string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        decryptedFile->push_back(new Point(line));
    }
    file.close();
    return decryptedFile;
}

void encryptFile(std::string fileName, map<Point*, std::string> data) {
    ofstream file(fileName);
    for (auto it = data.begin(); it != data.end(); it++) {
        file << it->first->toString() << "," << it->second << endl;
    }
    file.close();
}