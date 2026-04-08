#pragma once

template<typename T>

class IntList {
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node (T d); // declaration constructor
        ~Node(); // destructor
    };

    Node* head;
    Node* tail;
    int length;

public:
    IntList();
    ~IntList();

    // Copy constructor
    IntList(const IntList& other); // = delete 
                                   // if you dont want user to be able to copy list into another list/delete all copy constructors

    // Assignment Operator Overload
    IntList& operator=(const IntList& other);

    // Operator + Overload
    friend IntList operator+(const IntList& l1, const IntList& l2);

    T& operator[](int index);
    void add(T n);
    void print() const;
    int size() const;
    void clear();
};

#include "IntList.tpp"