#include <iostream>
#include <cstdlib>

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
    NodeIterator(Node<T>* sentinel) {
        currentNode = sentinel;
        endNode = sentinel;
    }
    bool next() {
        currentNode = currentNode->prev;
        return currentNode != endNode;
    }
    T& getCurrent() {
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
    void insert(T key);
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
void DoublyLinkedList<T>::insert(T key) {
    Node<T>* node = new Node<T>();
    node->key = key;
    node->prev = nil;
    node->next = nil->next;

    nil->next->prev = node;
    nil->next = node;
}

template<typename T>
void DoublyLinkedList<T>::remove(T key) {
    auto node = findNode(key);
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
    Node<T>* first = nil->prev;
    if (first == nullptr || first == nil) return;
    first->prev->next = nil;
    nil->prev = first->prev;
    delete first;
}

template<typename T>
void DoublyLinkedList<T>::removeLast() {
    Node<T>* last = nil->next;
    if (last == nullptr || last == nil) return;
    nil->next = last->next;
    last->next->prev = nil;
    delete last;
}

template<typename T>
NodeIterator<T> DoublyLinkedList<T>::getIterator() {
    return NodeIterator(nil);
}

int main() {
    DoublyLinkedList<int> list;
    list.insert(10);
    list.insert(11);
    list.insert(-9);
    auto ite = list.getIterator();
    while(ite.next()) {
        cout << ite.getCurrent() << endl;
    }
}
