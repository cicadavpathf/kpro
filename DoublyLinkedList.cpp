#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<typename T>
struct Node
{
    T key;
    Node<T>* prev;
    Node<T>* next;
};

template<typename T>
class NodeIterator
{
public:
    NodeIterator(Node<T>* startNode, Node<T>* nil) {
        currentNode = startNode;
        endNode = nil;
    }
    void next() {
        currentNode = currentNode->next;
    }
    bool peek() {
        return currentNode == endNode;
    }
    bool last() {
        return !peek() && currentNode->next == endNode;
    }
    T& getValue() {
        return currentNode->key;
    }
private:
    Node<T>* currentNode;
    Node<T>* endNode;
};

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add(T key);
    void remove(T key);
    void removeFirst();
    void removeLast();
    NodeIterator<T> getIterator();
private:
    Node<T>* nil;
    Node<T>* findNode(T key);
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    nil = new Node<T>();
    nil->next = nil;
    nil->prev = nil;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* node = nil->next;
    while (node != nil) {
        node = node->next;
        delete node->prev;
    }
    delete nil;
}

template<typename T>
void DoublyLinkedList<T>::add(T key) {
    Node<T>* node = new Node<T>();
    node->key = key;
    node->prev = nil;
    node->next = nil->next;

    nil->next->prev = node;
    nil->next = node;
}

template<typename T>
void DoublyLinkedList<T>::remove(T key) {
    Node<T>* node = findNode(key);
    if (node == nullptr || node == nil) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::findNode(T key) {
    Node<T>* node = nil->next;
    while (node != nil) {
        if (node->key == key) return node;
        node = node->next;
    }
    return nullptr;
}

template<typename T>
void DoublyLinkedList<T>::removeFirst() {
    Node<T>* first = nil->next;
    if (first == nullptr || first == nil) return;
    nil->next = first->next;
    first->next->prev = nil;
    delete first;
}

template<typename T>
void DoublyLinkedList<T>::removeLast() {
    Node<T>* last = nil->prev;
    if (last == nullptr || last == nil) return;
    last->prev->next = nil;
    nil->prev = last->prev;
    delete last;
}

template<typename T>
NodeIterator<T> DoublyLinkedList<T>::getIterator() {
    return NodeIterator(nil->next, nil);
}

int main() {
    int n;
    cin >> n;

    DoublyLinkedList<int> list;

    string cmd;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "deleteFirst") {
            list.removeFirst();
            continue;
        } else if (cmd == "deleteLast") {
            list.removeLast();
            continue;
        }

        cin >> x;
        if (cmd == "insert") {
            list.add(x);
        } else if (cmd == "delete") {
            list.remove(x);
        }
    }

    auto ite = list.getIterator();
    while (!ite.last()) {
        cout << ite.getValue() << " ";
        ite.next();
    }
    cout << ite.getValue() << endl;
}
