#include <iostream>
class Node {
    int _value;
    Node* next;
public:
    /*!
    \brief ����� �������� ������������� � ����������� ��� ������ Node.
    \param[in] value - ��������, ������� ����� �������� � �������� ����.
    */
    Node(const int value) { _value = value; next = nullptr; };
    friend class Deck;
};

class Deck {
    Node* head, * tail;
    size_t size;
    /*!
   \brief ������ ������������ �����������.
   \param[in] const Stack& - ������ �� Stack
   */
    Deck(const Deck&) = delete;
    /*!
    \brief ������ ��������� ������������ �����������.
    \param[in] const Stack& - ������ �� Stack
    */
    Deck& operator=(const Deck&) = delete;
    /*!
    \brief ������ ������������ �����������.
    \param[in] const Stack&& - ������ �� Stack
    */
    Deck(Deck&&) = delete;
    /*!
    \brief ������ ��������� ������������ �����������.
    \param[in] const Stack&& - ������ �� Stack
    */
    Deck& operator=(Deck&&) = delete;
public:
    /*!
    \brief ����� �������� ������������� �� ��������� ��� ������ Deck.
    */
    Deck() :head(nullptr), tail(nullptr), size(0) {};
    /*!
    \brief ���������� ������ ����� ������� � ��� ������.
    \param[in] value - ��������, ������� ����� �������� � �������� ����.
    */
    void pushR(const int value);
    /*!
    \brief ����� ������ ����� ������� � ��� �����.
    \param[in] value - ��������, ������� ����� �������� � �������� ����.
    */
    void pushL(const int value);
    /*!
    \brief ����� ������� �� ���� ������� ������.
    */
    int popR();
    /*!
    \brief ����� ������� �� ���� ������� �����.
    */
    int popL();
    /*!
    \brief ����� ���������� ���������� ��������� � ����.
    */
    size_t getSize();
    /*!
    \brief ����� �������� ������� ���� �����.
    \param[in] value - ��������, ������� ����� �������� � �������� ����.
    */
    void editL(const int value);
    /*!
    \brief ����� �������� ������� ���� ������.
    \param[in] value - ��������, ������� ����� �������� � �������� ����.
    */
    void editR(const int value);
    /*!
    \brief ����� ������� �� ������ ������� ���� �����.
    */
    int getL();
    /*!
    \brief ����� ������� �� ������ ������� ���� ������.
    */
    int getR();
    friend std::ostream& operator<< (std::ostream& out, Deck& deck);
};