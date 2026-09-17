#include <iostream>
using namespace std;

int main() {
    int rollNo[5];
    int search, i;
    bool found = false;

    cout << "Enter roll numbers of 5 students: ";

    for(i = 0; i < 5; i++) {
        cin >> rollNo[i];
    }

    cout << "Enter roll number to search: ";
    cin >> search;

    for(i = 0; i < 5; i++) {
        if(rollNo[i] == search) {
            found = true;
            break;
        }
    }

    if(found)
        cout << "Roll number found";
    else
        cout << "Roll number not found";

    return 0;
}
