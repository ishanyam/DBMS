#include <iostream>
class Node {
    int _value;
    Node* next;
public:
    /*!
    \brief Метод является конструктором с параметрами для класса Node.
    \param[in] value - значение, которое будет записано в элементе дека.
    */
    Node(const int value) { _value = value; next = nullptr; };
    friend class Deck;
};

class Deck {
    Node* head, * tail;
    size_t size;
public:
    /*!
    \brief Метод является конструктором по умолчанию для класса Deck.
    */
    Deck() :head(nullptr), tail(nullptr), size(0) {};
    /*!
    \brief МетодМетод вносит новый элемент в дек справа.
    \param[in] value - значение, которое будет записано в элементе дека.
    */
    void pushR(const int value);
    /*!
    \brief Метод вносит новый элемент в дек слева.
    \param[in] value - значение, которое будет записано в элементе дека.
    */
    void pushL(const int value);
    /*!
    \brief Метод удаляет из дека элемент справа.
    */
    int popR();
    /*!
    \brief Метод удаляет из дека элемент слева.
    */
    int popL();
    /*!
    \brief Метод возвращает количество элементов в деке.
    */
    size_t getSize();
    /*!
    \brief Метод изменяет элемент дека слева.
    \param[in] value - значение, которое будет записано в элементе дека.
    */
    void editL(const int value);
    /*!
    \brief Метод изменяет элемент дека справа.
    \param[in] value - значение, которое будет записано в элементе дека.
    */
    void editR(const int value);
    /*!
    \brief Метод выводит на печать элемент дека слева.
    */
    int getL();
    /*!
    \brief Метод выводит на печать элемент дека справа.
    */
    int getR();
    friend std::ostream& operator<< (std::ostream& out, Deck& deck);
};
