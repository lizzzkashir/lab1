#include "tasks.h"
#include <iostream>
#include <locale>
#include <limits>

void showMenu() {
    using namespace std;
    cout << "1. Rec10" << endl;
    cout << "2. Dyn1" << endl;
    cout << "3. Dyn17" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите задачу: ";
}

int main() {
    system("chcp 65001");

    using namespace std;

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;

        switch (choice) {
            case 1:
                cout << "Rec10" << endl;
                rec10m();
                break;
            case 2:
                cout << "Dyn1" << endl;
                dyn1m();
                break;
            case 3:
                cout << "Dyn17" << endl;
                dyndyn17m();
                break;
            case 0:
                cout << "конец" << endl;
                break;
            default:
                cout << "неверно" << endl;
        }
    } while (choice != 0);

    return 0;
}
