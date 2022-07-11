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
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }
        if (i != minIndex) {
            std::swap(a[i], a[minIndex]);
            swapCount++;
        }
    }
    
    printlnArray(a, n);
    printf("%d\n", swapCount);
}
