#include <fstream>
#include <vector>

using namespace std;


/**
 * Reads a file and decrypts it.
 * @param fileName name of the file
 * @param func function to decrypt the file
 * @return vector of decrypted objects
 */
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
/**
 * Writes a file and encrypts the data to it.
 * @param fileName name of the file
 * @param func function to encrypt to the file
 * @param data vector of encrypted objects
 */
template<typename T>
void encryptFile(string fileName, const string (func)(T), vector<T> data) {
    ofstream File(fileName);

    int size = data.size();
    for (int i = 0; i < size; i++) {
        File << func(data[i]) << endl;
    }
}

/**
 * Splits a string into a vector of strings.
 * @param line string to split
 * @param delimiter delimiter to split the string with
 * @return vector of strings
 */
vector<string> split(string line, char delimiter);
