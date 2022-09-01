#include <iostream>

using namespace std;

int n, l, k;
int a[100000];

bool solve(int border) {
    int count = 0;
    int sum = 0;
    int offset = 0;

    for(int i = 0; i < n; i++) {
        int piece = a[i] - offset;

        sum += piece;

        if (sum >= border) {
            count++;
            sum = 0;
        }

        offset = a[i];

        if (count >= k) break;
    }

    return count >= k && (sum + l - offset) >= border;
}

int biSearch() {
    int left = -1;
    int right = l;

    while(right - left > 1) {
        int mid = (left + right) / 2;
        if (solve(mid)) left = mid;
        else right = mid;
    }

    return left;
}

int main() {
    cin >> n >> l >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << biSearch() << endl;
}
