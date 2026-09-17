#include <iostream>
#include <string>

using namespace std;

int main() {
    int id1, id2, id3, id4;
    string title1, title2, title3, title4;

    cout << "Enter Book 1 ID: ";
    cin >> id1;
    cout << "Enter Book 1 Title: ";
    cin >> title1;

    cout << "Enter Book 2 ID: ";
    cin >> id2;
    cout << "Enter Book 2 Title: ";
    cin >> title2;

    cout << "Enter Book 3 ID: ";
    cin >> id3;
    cout << "Enter Book 3 Title: ";
    cin >> title3;

    cout << "Enter Book 4 ID: ";
    cin >> id4;
    cout << "Enter Book 4 Title: ";
    cin >> title4;

    cout << "\n-----LIBRARY BOOKS-----";
    cout << "\nBook ID: " << id1;
    cout << "\nBook Title: " << title1;

    cout << "\n\nBook ID: " << id2;
    cout << "\nBook Title: " << title2;

    cout << "\n\nBook ID: " << id3;
    cout << "\nBook Title: " << title3;

    cout << "\n\nBook ID: " << id4;
    cout << "\nBook Titile: " << title4;

    return 0;
}
