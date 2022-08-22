#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findCombiBits(const vector<int>& v, const int& target) {
    int n = v.size() > INT_MAX ? INT_MAX : static_cast<int>(v.size());
    
    int sum;
    for (int bi = 1; bi < (1 << n); bi++) {
        sum = 0;
        
        for (int i = 0, mask = 1; i < n; i++, mask = 1 << i) {
            if (bi & mask) sum += v[i];

            if (sum == target) return bi;
            else if (sum > target) break;
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> va(n);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }

    int q;
    cin >> q;

    int m;
    for (int i = 0; i < q; i++) {
        scanf("%d", &m);
        if (findCombiBits(va, m)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
