#include <iostream>
#include <string>

using namespace std;

uint32_t getRawKey(string& s) {
    uint32_t rawKey = 0;
    for (uint32_t code : s) {
        rawKey += code;
    }
    return rawKey;
}

size_t h1(uint32_t rawKey, size_t m) {
    return rawKey % m;
}
size_t h2(uint32_t rawKey, size_t m, int i) {
    return 1 + rawKey % (m - 1);
}
size_t hash(string* dict, int32_t rawKey, size_t m) {
    int i = 0;
    size_t hashVal;
    do {
        hashVal = (h1(rawKey, m) + i * h2(rawKey, m, i)) % m;
    } while (dict[hashVal].empty());
    
    return hashVal;
}

bool insert() {

}

int main() {
    string dictionary[1046527] = {};

    int n;
    cin >> n;

    string command;
    string key;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "insert") {
            
        } else if (command == "find") {

        }
    }
}
