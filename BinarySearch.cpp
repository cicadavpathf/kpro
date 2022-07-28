#include <iostream>
#include <vector>

using namespace std;

template<class Fn> void forExpression(int& n, Fn fn) {
    for (int i = 0; i < n; i++) fn(i);
}

bool biSearch(const vector<int>& v, int key) {
    size_t left = 0;
    size_t right = v.size();
    size_t mid;
    while (left < right) {
        mid = (left+right)/2;
        if (v[mid] == key) return true;
        if (v[mid] < key) left = mid+1;
        else if (v[mid] > key) right = mid;
    }
    return false;
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
    forExpression(q, [&count, &T, &S](int i) {
        count += static_cast<int>(biSearch(S, T[i]));
    });

    cout << count << endl;
}
