#include <iostream>
using namespace std;

void menu() {
    int choice;
    cout << "\n===== RESTAURANT MENU =====";
    cout << "\n1. Pizza";
    cout << "\n2. Burger";
    cout << "\n3. Pasta";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nYou selected Pizza.";
        menu();
    }
    else if (choice == 2) {
        cout << "\nYou selected Burger.";
        menu();
    }
    else if (choice == 3) {
        cout << "\nYou selected Pasta.";
        menu();
    }
    else if (choice == 4) {
        cout << "\nThank you!";
    }
    else {
        cout << "\nInvalid choice!";
        menu();
    }
}

int main() {
    menu();

    return 0;
}
