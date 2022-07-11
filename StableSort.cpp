#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template<typename T>
void printlnArray(T* a, size_t len) {
    for (size_t i = 0; i < len-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[len-1] << endl;
}

struct Card
{
    char suit;
    int number;
    bool operator ==(const Card& rhs) const;
};
bool Card::operator==(const Card& rhs) const {
    return suit == rhs.suit && number == rhs.number;
}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    return out << card.suit << card.number; 
}

int main() {
    constexpr int ARRAY_LENGTH = 36;

    int n = 0;
    scanf("%d", &n);

    Card a[ARRAY_LENGTH] = {};
    Card b[ARRAY_LENGTH] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i].suit >> a[i].number;
    }
    memcpy(b, a, sizeof(a));
    
    for (int i = 0, isSwapped = 1; isSwapped; i++) {
        isSwapped = 0;
        for (int j = n-1; j > i; j--) {
            if (a[j].number < a[j-1].number) {
                swap(a[j], a[j-1]);
                isSwapped = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (b[j].number < b[minIndex].number) minIndex = j;
        }
        if (minIndex != i) swap(b[i], b[minIndex]);
    }

    string resultA = "Stable";
    string resultB = equal(begin(a), end(a), begin(b)) ? "Stable" : "Not stable";

    printlnArray(a, n);
    cout << resultA << endl;
    printlnArray(b, n);
    cout << resultB << endl;
}
