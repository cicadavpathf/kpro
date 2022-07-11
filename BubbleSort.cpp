#include <iostream>
#include <cstdlib>

void printlnArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int a[100] = {};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int swapCount = 0;
    for (int i = 0, isSwapped = 1; isSwapped; i++) {
        isSwapped = 0;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                isSwapped = 1;
                swapCount++;
            }
        }
    }
    
    printlnArray(a, n);
    printf("%d\n", swapCount);
}
