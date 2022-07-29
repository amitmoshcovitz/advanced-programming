#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string line, char delimiter) {
    vector<string> resultVector;
    stringstream stringStream(line);
    string item;
    while (getline(stringStream, item, delimiter)) {
        resultVector.push_back(item);
    }
    return resultVector;
}