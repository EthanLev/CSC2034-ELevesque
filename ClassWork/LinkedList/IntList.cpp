#include "IntList.h"
#include <iostream>

IntList::Node::Node(int d)
    : data(d)
    , next(nullptr)
    , prev(nullptr) 
{
    std::cout << "Creating Node" << std::endl;
}

IntList::Node::~Node() {
    std::cout << "Destroying Node" << std::endl;
}

IntList::IntList()
    : head(nullptr)
    , tail(nullptr)
    , length(0)
{
    std::cout << "Creating List" << std::endl;
}

IntList::~IntList() {
    clear();
    std::cout << "Destroying List" << std::endl;
}

// Copy constructor
IntList::IntList(const IntList& other) 
    : IntList()
{
    // for each node in original list, copy to this list
    for (auto n = other.head; n; n = n -> next) {
        add(n->data);
    }
}

void IntList::add(int n) {
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

void IntList::print() const {
    for (Node* n = head; n; n = n->next) {
        std::cout << n->data << ' ';
    }

    std::cout << '\n';
}

int IntList::size() const {
    return length;
}

void IntList::clear() {
    Node* n = head;

    while (n) {
        Node* temp = n->next;
        delete n;
        n = temp;
    }

    head = tail = nullptr;
    length = 0;
}