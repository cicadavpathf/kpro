#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int loadIntoTruck(int maxTruckNum, int capacity, vector<int>& loads) {
    int truckNum = 1;
    int loadCount = 0;
    int weight = 0;

    for (size_t i = 0; i < loads.size(); i++) {
        int weightSum = weight + loads[i];

        if (capacity < weightSum) {
            truckNum++;
            if (maxTruckNum < truckNum || capacity < loads[i]) break;
            weightSum = loads[i];
        }

        weight = weightSum;
        loadCount++;
    }
    return loadCount;
}

int main() {
    int n = 0;
    int k = 0;
    cin >> n >> k;
    
    auto vecW = vector<int>(n);
    
    int w = 0;
    int sumW = 0;
    for (int i = 0; i < n; i++) {
        cin >> w;
        vecW[i] = w;
        sumW += w;
    }

    int left = 0;
    int right = sumW;
    while(left < right) {
        int mid = (left + right) / 2;
        int q = loadIntoTruck(k, mid, vecW);
        if (q >= n) right = mid;
        else left = mid + 1;
    }

    cout << right << endl;
}
