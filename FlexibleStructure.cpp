#include <iostream>
#include <cstdlib>

struct Flexible
{
    int size;
    int values[0];
};

int main() {
    int n;

    std::cin >> n;

    struct Flexible* a = (struct Flexible*)malloc(sizeof(struct Flexible) + n * sizeof(int));
    a->size = n;

    std::cout << "(struct Flexible*)a values:" << std::endl;
    for (int i = 0; i < a->size; i++) {
        a->values[i] = i;
        printf("%d ", a->values[i]);
    }
    printf("\n");

    free(a);
}
