#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int32_t>& a, size_t left, size_t mid, size_t right) {
    vector<int32_t> leftVector(mid - left);
    for (size_t i = 0; i < leftVector.size(); i++) leftVector[i] = a[left + i];
    vector<int32_t> rightVector(right - mid);
    for (size_t i = 0; i < rightVector.size(); i++) rightVector[i] = a[mid + i];

    size_t leftIndex = 0, rightIndex = 0;

    for (size_t i = 0; i < right - left; i++) {
        if (rightIndex >= rightVector.size()) {
            a[left + i] = leftVector[leftIndex++];
        } else if (leftIndex >= leftVector.size()) {
            a[left + i] = rightVector[rightIndex++];
        } else if (leftVector[leftIndex] <= rightVector[rightIndex])
            a[left + i] = leftVector[leftIndex++];
        else
            a[left + i] = rightVector[rightIndex++];
    }
}

void mergeSort(vector<int32_t>& a, size_t left, size_t right) {
    if (left + 1 < right) {
        size_t mid = (left + right) / 2;

	mergeSort(a, left, mid);
	mergeSort(a, mid, right);
        merge(a, left, mid, right);       
    }
}

int main() {
    size_t n;
    cin >> n;
    
    vector<int32_t> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, a.size());

    for (size_t i = 0; i < a.size(); i++) {
        if (i) cout << " ";
	cout << a[i];
    }
    cout << endl;
}
