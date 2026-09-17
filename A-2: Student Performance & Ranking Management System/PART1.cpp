#include <iostream>
using namespace std;

int main() {
    int rollNo[6];

    cout << "Enter Roll Numbers of 5 students:\n";

    for (int i = 0; i < 6; i++) {
        cin >> rollNo[i];
    }

    cout << "\nStudent Roll Numbers:\n";

    for (int i = 0; i < 6; i++) {
        cout << rollNo[i] << endl;
    }

    return 0;
}
