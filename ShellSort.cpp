#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
void printlnArray(T a[], size_t n) {
    for (size_t i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

constexpr size_t MAX_ARRAY_LEN = 1000000;
constexpr size_t MAX_GAP = 100;

size_t setupGapArray(int g[], int n) {
    size_t m = 1;
    int h = 1;
    for (int th = 1; th < n && m <= MAX_GAP; th = h*3+1) {
        h = th;
        m++;
    }

    size_t i;
    for (i = 0; h > 0; h /= 3) {
        g[i++] = h;
    }
    return i;
}

void insertionSort(int a[], size_t n, int& g, uint64_t& count) {
    for (size_t i = g; i < n; i++) {
        int v = a[i];
        int j = i-g;
        while (j >= 0 && a[j] > v) {
            a[j+g] = a[j];
            j -= g;
            count++;
        }
        a[j+g] = v;
    }
}

void shellSort(int a[], size_t n, int g[], size_t m, uint64_t& count) {
    for (size_t i = 0; i < m; i++) {
        insertionSort(a, n, g[i], count);
    }
}

int main() {
    int a[MAX_ARRAY_LEN] = {};
    int g[MAX_GAP] = {};
    uint64_t cnt = 0;

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m = setupGapArray(g, n);
    shellSort(a, n, g, m, cnt);

    cout << m << endl;
    printlnArray(g, m);
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
