#include <iostream>
#include <cstdlib>
#include <vector>

void printlnVec(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; i++) {
        printf("%d ", vec[i]);
    }
    printf("%d\n", vec[vec.size() - 1]);
}

int main() {
    int n = 0;
    scanf("%d", &n);

    std::vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printlnVec(a);

    for (size_t i = 1; i < a.size(); i++) {
        int v = a[i];
        size_t j = i;
        while (j > 0 && v < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
        
        printlnVec(a);
    }
}
