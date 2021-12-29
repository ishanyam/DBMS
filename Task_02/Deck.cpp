#include "Deck.h"
#include <sstream>
#include <string>

size_t Deck::getSize() {
    return size;
};
void Deck::pushR(const int value) {
    Node* temp = new Node(value);
    if (tail == nullptr) {
        tail = head = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    };
    size++;
};
void Deck::pushL(const int value) {
    Node* temp = new Node(value);
    if (head == nullptr) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    };
    size++;
};
int Deck::popR() {
    const int value = tail->_value;
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* tempNode = head;
        for (int i = 1; i < size - 1; i++) {
            tempNode = tempNode->next;
        }
        tempNode->next = nullptr;
        delete tail;
        tail = tempNode;
    };
    size--;
    return value;
};
int Deck::popL() {
    const int value = head->_value;
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* temphead = head->next;
        delete head;
        head = temphead;
    }
    size--;
    return value;
};
void Deck::editL(const int value) {
    this->popL();
    this->pushL(value);
};
void Deck::editR(const int value) {
    this->popR();
    this->pushR(value);
};
int Deck::getL() {
    return head->_value;
};
int Deck::getR() {
    return tail->_value;
};
std::ostream& operator<< (std::ostream& out, Deck& deck)
{
    std::string ret;
    const size_t size = deck.getSize();
    for (int i = 0; i < size; i++) {
        std::ostringstream temp;
        temp << deck.popL();
        ret += temp.str() + " ";
    };
    return out << ret;
};
