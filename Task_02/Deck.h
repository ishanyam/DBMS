#include <iostream>
class Node {
public:
    int x;
    Node* Next;
};

class Deck {
    Node* Head, * Tail;
    size_t size;
public:
    Deck() :Head(nullptr), Tail(nullptr), size(0) {};
    void pushR(const int x);
    void pushL(const int x);
    void popR();
    void popL();
    size_t getSize();
    void editL(Deck M, const int x);
    void editR(Deck M, const int x);
    int printR();
    int printL();
};