#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;

    if (s[0] == '1') {
        cout << "No" << endl;
        return 0;
    }

    bool col[7] = {
        s[6] == '1',
        s[3] == '1',
        s[1] == '1' || s[7] == '1',
        s[4] == '1',
        s[2] == '1' || s[8] == '1',
        s[5] == '1',
        s[9] == '1',
    };

    bool begin = false;
    bool hasEmpty = false;
    bool isSplit = false;
    for (int i = 0; i < 7; i++) {
        if(begin && hasEmpty && col[i]) {
            isSplit = true;
            break;
        } else if(begin && !col[i]) {
            hasEmpty = true;
        } else if(col[i]) {
            begin = true;
        }
    }

    cout << (isSplit ? "Yes" : "No") << endl;
}
