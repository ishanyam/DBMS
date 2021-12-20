#include "Deck.h"

size_t Deck::getSize() {
    return size;
};
void Deck::pushR(const int x) {
    Node* temp = new Node;
    temp->x = x;
    if (Tail == nullptr) {
        Tail = Head = temp;
    }
    else {
        Tail->Next = temp;
        Tail = temp;
    };
    size++;
};
void Deck::pushL(const int x) {
    Node* temp = new Node;
    temp->x = x;
    if (Head == nullptr) {
        Head = Tail = temp;
    }
    else {
        temp->Next = Head;
        Head = temp;
    };
    size++;
};
void Deck::popR() {
    if (size == 1) {
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
    else {
        Node* tempNode = Head;
        for (int i = 1; i < size - 1; i++) {
            tempNode = tempNode->Next;
        }
        tempNode->Next = nullptr;
        delete Tail;
        Tail = tempNode;
    };
    size--;
};
void Deck::popL() {
    if (size == 1) {
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
    else {
        Node* tempHead = Head->Next;
        delete Head;
        Head = tempHead;
    }
    size--;
};
void Deck::editL(Deck M, const int x) {
    M.popL();
    M.pushL(x);
};
void Deck::editR(Deck M, const int x) {
    M.popR();
    M.pushR(x);
};
int Deck::printL() {
    return Head->x;
};
int Deck::printR() {
    return Tail->x;
};