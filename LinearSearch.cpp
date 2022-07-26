#include <iostream>
#include <vector>

using namespace std;

template<class Fn> void forExpression(int& n, Fn fn) {
    for (int i = 0; i < n; i++) fn(i);
}

int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    forExpression(n, [&S](int i) {
        int s;
        cin >> s;
        S[i] = s;
    });
    int q;
    cin >> q;
    vector<int> T(q);
    forExpression(q, [&T](int i) {
        int t;
        cin >> t;
        T[i] = t;
    });

    int count = 0;

    for (int t : T) {
        S.push_back(t);

        size_t i = 0;
        while (S[i] != t) i++;
        if (i != S.size()-1) count++;

        S.pop_back();
    }

    cout << count << endl;
}
