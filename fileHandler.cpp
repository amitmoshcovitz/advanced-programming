#include <fstream>

using namespace std;

void** decryptFile(const char* fileName, const void* (func)(char*)) {
    ifstream File(fileName);

    string line;
    void** result = NULL;
    int count = 0;
    while (getline(File, line)) {
        result = (void**)realloc(result, sizeof(void*) * (++count));
        result[count - 1] = func(buffer);
    }

    return result;
}

void encryptFile(const char* fileName, const char* (func)(void*)) {
    FILE* file = fopen(fileName, "w");
    if (!file) {
        return;
    }

    void** result = decryptFile(fileName, func);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s", result[i]);
    }
}