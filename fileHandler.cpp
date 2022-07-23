#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


template<typename T>
vector<T> decryptFile(string fileName, T (func)(string)) {
    ifstream File(fileName);

    string line;
    int count = 0;
    vector<T> resultVector;

    while (getline(File, line)) {
        resultVector.push_back(func(line));
    }

    return resultVector;
}

template<typename T>
void encryptFile(string fileName, const string (func)(T), vector<T> data) {
    ofstream File(fileName);

    int size = data.size();
    for (int i = 0; i < size; i++) {
        File << func(data[i]) << endl;
    }
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