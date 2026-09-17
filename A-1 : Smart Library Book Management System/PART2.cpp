#include <iostream>
using namespace std;

int main() {
    int book[6];
    int searchID;

    cout << "Enter 6 Book IDs:\n";

    for (int i = 0; i < 6; i++) {
       cin >> book[i];
    }

    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    for (int i = 0; i < 6; i++)
    {
        if (book[i] == searchID)
        {
            cout << "Book Found!";
            return 0;
        }
    }

    cout << "Book Not Found!";

    return 0;
}
