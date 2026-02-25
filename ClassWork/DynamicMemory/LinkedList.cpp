#include <iostream>

struct Data {
    int num;
};

struct Node {
    Data* data;
    Node* next;

    ~Node() {
        delete data;
        std::cout << "Deleted data" << std::endl;
        std::cout << "Deleted node" << std::endl;
    }
};

struct LinkedList {
    Node* head = nullptr;
    size_t size = 0;

    ~LinkedList() {
        Node* node = head;
        
        while(node) {
            Node* restOfList = node->next;
            delete node;
            node = restOfList;
        }

        std::cout << "Deleted list" << std::endl;
    }
};

LinkedList createList(int size) {
    LinkedList list {nullptr, 0};

    srand(56);

    for (size_t i = 0; i < size; i++) {
        Node*  node = new Node{nullptr, nullptr}; // empty node
        Data* data = new Data{rand()};
        node->data = data; // set data in node
        node->next = list.head; // set
        list.head = node; 
        list.size++;
    }

    return list;
}

int main(int, char**) {
    int count = 3;
    LinkedList list = createList(count);

    Node* node = list.head;

    while (node) {
        std::cout << "Data: " << node->data->num << std::endl;
        node = node->next;
    }
}