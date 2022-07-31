#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

constexpr size_t DICTIONARY_SIZE = 1046527;
constexpr size_t VALUE_SIZE = 12;
constexpr size_t COMMAND_SIZE = 6;

/*
最初、制限時間超過(TLE)に引っかかって苦戦した。
std::stringとsmart pointerを捨て、cstringを使用してコード改造したが、全く解決できなかった。
真の原因はgetRawKeyで重みpを使用していなかったこと。
重みを乗せないと、ACGとGCAが同じ数値になってしまうため、hash値が被ってしまい
計算量が爆増していた。
*/

uint32_t getRawKey(const char s[]) {
    uint32_t sum = 0;
    uint32_t p = 1;
    for (size_t i = 0; i < strlen(s); i++) {
        sum += (s[i] - 0x40) * p;
        p *= 5;
    }
    return sum;
}

size_t h1(const uint32_t& rawKey, const size_t& m) {
    return rawKey % m;
}
size_t h2(const uint32_t& rawKey, const size_t& m) {
    return 1 + rawKey % (m - 1);
}
size_t generateHash(const uint32_t& rawKey, const size_t& m, const int& i) {
    return (h1(rawKey, m) + i * h2(rawKey, m)) % m;
}

void insert(char (&dictionary)[DICTIONARY_SIZE][VALUE_SIZE], const char v[]) {
    uint32_t rawKey = getRawKey(v);

    size_t hashVal;
    for (size_t count = 0; count < DICTIONARY_SIZE; count++) {
        hashVal = generateHash(rawKey, DICTIONARY_SIZE, count);

        if (strcmp(dictionary[hashVal], v) == 0) return;
        else if (strlen(dictionary[hashVal]) == 0) {
            strcpy(dictionary[hashVal], v);
            return;
        }
    }
}

bool find(char (&dictionary)[DICTIONARY_SIZE][VALUE_SIZE], const char v[]) {
    uint32_t rawKey = getRawKey(v);

    size_t hashVal;
    for (size_t count = 0; count < DICTIONARY_SIZE; count++) {
        hashVal = generateHash(rawKey, DICTIONARY_SIZE, count);

        if (strcmp(dictionary[hashVal], v) == 0) return true;
        else if (strlen(dictionary[hashVal]) == 0) return false;
    }
    return false;
}

int main() {
    char dictionary[DICTIONARY_SIZE][VALUE_SIZE];

    int n;
    scanf("%d", &n);

    char command[COMMAND_SIZE] = {};
    char value[VALUE_SIZE] = {};
    for (int i = 0; i < n; i++) {
        scanf("%s %s", command, value);
        if (command[0] == 'i') {
            insert(dictionary, value);
        } else if (command[0] == 'f') {
            if (find(dictionary, value)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}
