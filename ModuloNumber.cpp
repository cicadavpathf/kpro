#include <iostream>
#include <string>

using namespace std;

const int mod = 998244353;

int main() {
    long long n;
    cin >> n;
    long long m = n % mod;
    if (m < 0) m += mod;

    cout << m << endl;
}
