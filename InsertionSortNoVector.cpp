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
    
    printlnArray(a, n);

    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i;
        while (j > 0 && v < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
        
        printlnArray(a, n);
    }
}
