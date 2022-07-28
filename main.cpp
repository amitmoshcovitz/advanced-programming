#include "fileHandler.hpp"
#include "iris.hpp"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Converts a line into an Iris object.
 * @param line line to convert
 * @return Iris object
 */
Iris decryptToIris(string line) {
    vector<string> fields = split(line, ',');
    return Iris(stod(fields[0]), stod(fields[1]), stod(fields[2]), stod(fields[3]), Iris::getIrisType(fields[4]));
}

int main(int argc, char const *argv[]) {
    vector<Iris> irisData = decryptFile<Iris>("iris.csv", decryptToIris);
    return 0;
}
