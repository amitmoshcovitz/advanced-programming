#include <map>
#include "point.h"
#include <sstream>

using namespace std;


/**
 * Reads a file and decrypts it.
 * @param fileName name of the file
 * @param func function to decrypt the file
 * @return map of decrypted objects
 */
map<Point, string> decryptFile(string fileName);

/**
 * Writes a file and encrypts the data to it.
 * @param fileName name of the file
 * @param func function to encrypt to the file
 * @param data map of encrypted objects
 */
void encryptFile(string fileName, map<Point, string> data);

/**
 * Splits a string into a vector of strings.
 * @param line string to split
 * @param delimiter delimiter to split the string with
 * @return vector of strings
 */
vector<string> split(string line, char delimiter);
