#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
struct Node
{
    T key;
    Node* prev;
    Node* next;
};

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(T key);
private:
    Node<T>* nil;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    nil = new Node<T>();
    nil->key = nullptr;
    nil->next = nil;
    nil->prev = nil;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
}

template<typename T>
void DoublyLinkedList<T>::insert(T key) {
    Node<T>* node = new Node<T>(key);
    node->key = key;
    node->next = nil->next;
    node->prev = nil;

    nil->next->prev = node;
    nil->next = node;
}

int main() {

}
