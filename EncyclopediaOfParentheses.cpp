#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

vector<string> solve() {
    vector<string> validList;

    int max = (1 << n) - 1;

    validList.reserve(max);

    for (int bit = 0; bit <= max; bit++) {
        int count = 0;
        char parentheses[n];

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                count++;
                parentheses[i] = '(';
            } else {
                count--;
                parentheses[i] = ')';
            }

            if (count < 0) break;
        }

        if (count == 0) validList.push_back(string(parentheses, n));
    }

    sort(validList.begin(), validList.end());
    return validList;
}

int main() {
    cin >> n;

    vector<string> result = solve();

    for (auto ans : result) {
        cout << ans << endl;
    }
}
