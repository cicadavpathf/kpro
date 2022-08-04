#include <iostream>
#include <vector>

using namespace std;

int loadIntoTruck(int maxTruckNum, int capacity, vector<int>& loads) {
    int truckNum = 1;
    int loadCount = 0;
    int weight = 0;

    for (size_t i = 0; i < loads.size(); i++) {
        int weightSum = weight + loads[i];

        if (capacity < weightSum) {
            truckNum++;
            if (maxTruckNum < truckNum) break;
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
    cin >> n;
    cin >> k;
    
    auto vecW = vector<int>(n);
    
    int w = 0;
    for (int i = 0; i < n; i++) {
        cin >> w;
        vecW[i] = w;
    }

    // wのmaxを取得し、nに合致するloadIntoTruckの戻り値を二分探索で求める
    // nに合致する時の引数capacityが答え
}
