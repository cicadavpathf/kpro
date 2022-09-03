#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<long long int> a;

int main() {
    cin >> n >> m;
    a.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long int> sumA(n + 1);
    for(int i = 1; i < n + 1; i++) {
        sumA[i] = sumA[i - 1] + a[i - 1];
    }

    vector<long long int> sumMList(n - m + 1);

    for(int i = 0; i < m; i++) sumMList[0] += (i + 1) * a[i];
    
    for(int i = 1; i < n - m + 1; i++) {
        long long int sumPartA = sumA[i + m - 1] - sumA[i - 1];
        sumMList[i] = sumMList[i - 1] - sumPartA + m * a[i + m - 1];
    }
    cout << *max_element(sumMList.begin(), sumMList.end()) << endl;
}
