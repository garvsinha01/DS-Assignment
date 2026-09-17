#include <iostream>
using namespace std;

int main() {
    int stack[5];
    int top = -1;

    cout << "Enter 5 Cancelled Order Numbers:\n";

    for (int i = 0; i < 5; i++) {
        cin >> stack[++top];
    }

    cout << "\nCancelled Orders (Most Recent First):\n";

    while (top >= 0) {
        cout << stack[top] << endl;
        top--;
    }

    return 0;
}
