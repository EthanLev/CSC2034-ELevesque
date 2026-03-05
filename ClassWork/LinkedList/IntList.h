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

    // Copy constructor
    IntList(const IntList& other); // = delete 
                                   // if you dont want user to be able to copy list into another list/delete all copy constructors

    // Assignment Operator Overload
    IntList& operator=(const IntList& other);

    // Operator + Overload
    friend IntList operator+(const IntList& l1, const IntList& l2);

    void add(int n);
    void print() const;
    int size() const;
    void clear();
};