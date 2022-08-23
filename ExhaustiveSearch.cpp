#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> collectSumCombination(const vector<int>& inVec) {
    int n = inVec.size();
    vector<int> outVec(1 << n);
    
    for (int bit = 1; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            if (bit & mask) outVec[bit] += inVec[i];
        }
    }

    return outVec;
}

int binarySearchIndex(const vector<int>& inVec, int target) {
    int left = -1;
    int right = static_cast<int>(inVec.size());
    
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (target <= inVec[mid]) right = mid;
        else left = mid;
    }

    return right;
}

int main() {
    int n;
    cin >> n;

    vector<int> vecA(n);
    for (int i = 0; i < n; i++) {
        cin >> vecA[i];
    }
    
    auto vecSums = collectSumCombination(vecA);
    sort(vecSums.begin(), vecSums.end());
    vecSums.erase(unique(vecSums.begin(), vecSums.end()), vecSums.end());
    
    int q;
    cin >> q;
    
    int m;
    for (int i = 0; i < q; i++) {
        cin >> m;
        int lowerBoundIndex = binarySearchIndex(vecSums, m);
        if (vecSums[lowerBoundIndex] == m) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
