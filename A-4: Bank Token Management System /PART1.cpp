#include <iostream>
using namespace std;

int main() {
    int queue[5];
    int front = 0;
    int rear = 0;

    cout << "Enter 5 Customer Token Numbers:\n";

    for (int i = 0; i < 5; i++) {
        cin >> queue[rear];
        rear++;
    }

    cout << "\nServing Customers:\n";

    while (front < rear) {
        cout << "Serving Customer with Token: "
             << queue[front] << endl;
        front++;
    }

    return 0;
}
