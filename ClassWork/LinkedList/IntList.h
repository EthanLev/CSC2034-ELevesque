class IntList {
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node (int d); // declaration constructor
        ~Node(); // destructor
    };

    Node* head;
    Node* tail;
    int length;

public:
    IntList();
    ~IntList();

    void add(int n);
    void print() const;
    int size() const;
    void clear();
};