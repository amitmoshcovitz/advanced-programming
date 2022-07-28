#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include "point.h"
#include "fileHandler.h"

using namespace std;

map<Point, string> decryptFile(string fileName) {
    map<Point, string> decryptedFile;
    ifstream file(fileName);
    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        int seperatorIndex = line.find_last_of(",");
        decryptedFile[Point(line.substr(0, seperatorIndex))] = line.substr(seperatorIndex + 1);
    }
    file.close();
    return decryptedFile;
}


void encryptFile(string fileName, map<Point, string> data) {
    ofstream file(fileName);
    for (auto it = data.begin(); it != data.end(); it++) {
        file << it->first.toString() << "," << it->second << endl;
    }
    file.close();
}


vector<string> split(string line, char delimiter) {
    vector<string> resultVector;
    stringstream stringStream(line);
    string item;
    while (getline(stringStream, item, delimiter)) {
        resultVector.push_back(item);
    }
    return resultVector;
}