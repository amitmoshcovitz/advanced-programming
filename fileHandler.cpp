#include <vector>
#include <fstream>
#include <map>
#include "point.h"
#include "fileHandler.h"

using namespace std;

map<std::unique_ptr<Point>, string> decryptClassifiedFile(string fileName) {
    map<std::unique_ptr<Point>, string> decryptedFile;
    ifstream file(fileName);
    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        int seperatorIndex = line.find_last_of(",");
        std::unique_ptr<Point> p(new Point(line.substr(0, seperatorIndex)));
        decryptedFile[std::move(p)] = line.substr(seperatorIndex + 1);
    }
    file.close();
    return decryptedFile;
}

vector<std::unique_ptr<Point>> decryptUnclassifiedFile(string fileName) {
    vector<std::unique_ptr<Point>> decryptedFile;
    ifstream file(fileName);
    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        std::unique_ptr<Point> p(new Point(line));
        decryptedFile.push_back(std::move(p));
    }
    file.close();
    return decryptedFile;
}

void encryptFile(string fileName, map<std::unique_ptr<Point>, string> data) {
    ofstream file(fileName);
    for (auto it = data.begin(); it != data.end(); it++) {
        file << it->first->toString() << "," << it->second << endl;
    }
    file.close();
}