#include <iostream>
using namespace std;

int main() {
    int book[6];
    int temp;

    cout << "Enter IDs of 6 Library Books:\n";

    for (int i = 0; i < 6; i++) {
        cin >> book[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++)
        {
            if (book[j] > book[j + 1]) {
                temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }

    cout << "\nBook IDs in Ascending Order:\n";

    for (int i = 0; i < 6; i++) {
        cout << book[i] << " ";
    }

    return 0;
}
