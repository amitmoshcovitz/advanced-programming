#include <fstream>
#include <vector>

using namespace std;

vector<void*> decryptFile(string fileName, void* (func)(string)) {
    ifstream File(fileName);

    string line;
    int count = 0;
    vector<void*> resultVector;

    while (getline(File, line)) {
        resultVector.push_back(func(line));
    }

    return resultVector;
}

void encryptFile(string fileName, const string (func)(void*), vector<void*> data) {
    ofstream File(fileName);

    int size = data.size();
    for (int i = 0; i < size; i++) {
        File << func(data[i]) << endl;
    }
}