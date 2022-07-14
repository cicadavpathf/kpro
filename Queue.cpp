#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Process
{
    string name;
    int time;
};

class ProcessQueue
{
public:
    ProcessQueue(int n) {
        bufferSize = n+1;
        ringBuffer = new Process[bufferSize]();
        head = 0;
        tail = 0;
    }
    ~ProcessQueue() {
        if (ringBuffer != nullptr)
            delete[] ringBuffer;
    }
    bool isFull() {
        return head == (tail+1)%bufferSize;
    }
    bool isEmpty() {
        return head == tail;
    }
    bool enqueue(Process proc) {
        if (isFull()) {
            return false;
        }
        ringBuffer[tail] = proc;
        tail = (tail+1)%bufferSize;
        return true;
    }
    Process dequeue() {
        int index = head;
        head = (head+1)%bufferSize;
        return ringBuffer[index];
    }
private:
    Process* ringBuffer;
    int bufferSize;
    int head;
    int tail;
};

int main() {
    int n = 0;
    int timeQuantum = 0;
    cin >> n >> timeQuantum;

    char nameBuff[11]; // 10 chars + 1(null-terminated)
    int time;
    auto q = ProcessQueue(n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", nameBuff, &time);
        q.enqueue(Process{string(nameBuff), time});
    }

    int elapsedTime = 0;
    while (!q.isEmpty()) {
        auto proc = q.dequeue();
        
        proc.time -= timeQuantum;
        if (proc.time > 0) {
            elapsedTime += timeQuantum;
            q.enqueue(proc);
        } else {
            elapsedTime += timeQuantum+proc.time;
            printf("%s %d\n", proc.name.c_str(), elapsedTime);
        }
    }
}
