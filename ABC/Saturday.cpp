#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> Dow {
    {"Monday", 0},
    {"Tuesday", 1},
    {"Wednesday", 2},
    {"Thursday", 3},
    {"Friday", 4},
    {"Saturday", 5},
};

string s;

int main() {
    cin >> s;

    cout << Dow.at("Saturday") - Dow.at(s) << endl;
}
