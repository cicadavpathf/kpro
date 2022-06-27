#include <iostream>
#include <cstdlib>

int main()
{
    int n, len;
    int max, sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &len);
        if (len > max) {
            max = len;
        }
        sum += len;
    }

    if (sum > max * 2) {
        printf("yes");
    } else {
        printf("no");
    }
}