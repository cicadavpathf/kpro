#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Stack
{
public:
    Stack(int n) {
        s = new int[n]();
        n_ = n;
        cursor = 0;
    }
    ~Stack() {
        if (s != nullptr) delete[] s;
    }
    bool isFull() {
        return n_ <= cursor;
    }
    bool isEmpty() {
        return cursor <= 0;
    }
    bool push(int a) {
        if (isFull()) {
            return false;
        }
        s[cursor++] = a;
        return true;
    }
    int pop() {
        return s[--cursor];
    }
private:
    int* s;
    int n_;
    int cursor;
};

int main() {
    Stack s(199);

    string a;
    while (cin >> a) {
        if (a == "+") {
            s.push(s.pop() + s.pop());
        } else if (a == "-") {
            int r = s.pop();
            int l = s.pop();
            s.push(l - r);
        } else if (a == "*") {
            s.push(s.pop() * s.pop());
        } else {
            s.push(stoi(a));
        }
    }

    cout << s.pop() << endl;
}
