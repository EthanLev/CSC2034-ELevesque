#include "IntList.h"
#include <iostream>

template<typename T>
IntList<T>::Node::Node(T d)
    : data(d)
    , next(nullptr)
    , prev(nullptr) 
{
    //std::cout << "Creating Node" << std::endl;
}

template<typename T>
IntList<T>::Node::~Node() {
    //std::cout << "Destroying Node" << std::endl;
}

template<typename T>
IntList<T>::IntList()
    : head(nullptr)
    , tail(nullptr)
    , length(0)
{
    //std::cout << "Creating List" << std::endl;
}

template<typename T>
IntList<T>::~IntList() {
    clear();
    //std::cout << "Destroying List" << std::endl;
}

template<typename T>
// Copy constructor
IntList<T>::IntList(const IntList& other) 
    : IntList()
{
    // for each node in original list, copy to this list
    for (auto n = other.head; n; n = n -> next) {
        add(n->data);
    }
}

template<typename T>
// Overloading Assignment Operator
IntList<T>& IntList<T>::operator=(const IntList<T>& other) { 

    // Invoke copy constructor
    IntList temp {other};

    std::swap(this->head, temp.head);
    std::swap(this->tail, temp.tail);
    std::swap(this->length, temp.length);

    return *this;
}

template<typename T>
IntList<T> operator+(const IntList<T>& l1, const IntList<T>& l2) {

    // Invoke copy constructor
    IntList result{l1};

    for (auto n = l2.head; n; n = n -> next) {
        result.add(n->data);
    }

    return result;
}

template<typename T>
void IntList<T>::add(T n) {
    IntList::Node* new_node = new Node(n); // create new node with data

    if (tail) {                 // if tail exists
        new_node->prev = tail;  //
        tail->next = new_node;  // tail.next = new node
        tail = new_node;        // 
    } else {                    // tail doesn't exist at first
        head = tail = new_node; // head and tail = new node
    }

    length++;
}

template<typename T>
void IntList<T>::print() const {
    for (Node* n = head; n; n = n->next) {
        std::cout << n->data << ' ';
    }

    std::cout << '\n';
}

template<typename T>
int IntList<T>::size() const {
    return length;
}

template<typename T>
void IntList<T>::clear() {
    Node* n = head;

    while (n) {
        Node* temp = n->next;
        delete n;
        n = temp;
    }

    head = tail = nullptr;
    length = 0;
}