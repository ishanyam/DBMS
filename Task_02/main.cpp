#include "Deck.h"

using namespace std;

void printMENU() {
    cout << "\n     MENU\n\n";
    cout << "1) Print Deck\n";
    cout << "2) Append element (Left)\n";
    cout << "3) Append element (Right)\n";
    cout << "4) Delete element (Left)\n";
    cout << "5) Delete element (Right)\n";
    cout << "6) Edit element (Left)\n";
    cout << "7) Edit element (Right)\n";
    cout << "\nQuit - q\n";
}

void printElements(Deck M) {
    if (M.getSize() == 0) {
        cout << "Deck is empty!" << endl;
    }
    else if (M.getSize() == 1) {
        cout << M.printL() << endl;
    }
    else {
        cout << M.printL() << " ";
        for (int i = 2; i < M.getSize(); i++) {
            cout << "__ ";
        };
        cout << M.printR() << endl;
    }
};

int main()
{
    Deck M;
    char key = '0';
    while (key != 'q') {
        system("cls");
        printMENU();
        cin >> key;
        int k = 0;
        switch (key) {
        case '1':
            cout << "Deck items:" << endl;
            printElements(M);
            break;
        case '2':
            cout << "Enter element to append: ";
            cin >> k;
            M.pushL(k);
            cout << "Done." << endl;
            break;
        case '3':
            cout << "Enter element to append: ";
            cin >> k;
            M.pushR(k);
            cout << "Done." << endl;
            break;
        case '4':
            M.popL();
            cout << "Done." << endl;
            break;
        case '5':
            M.popR();
            cout << "Done." << endl;
            break;
        case '6':
            cin >> k;
            M.editL(M, k);
            cout << "Done." << endl;
            break;
        case '7':
            cin >> k;
            M.editR(M, k);
            cout << "Done." << endl;
            break;
        }
        system("pause");
    }
    return 0;
}