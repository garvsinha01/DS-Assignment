#include <iostream>
using namespace std;

int main() {
    int rollNo[5];

    for (int i = 0; i < 5; i++) {
        cin >> rollNo[i];
    }

    cout << "\nStudent RollNo:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << rollNo[i] << endl;
    }

    return 0;
}
