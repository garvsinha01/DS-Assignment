#include <iostream>
using namespace std;

int main() {
    int stack[5];
    int top = -1;

    cout << "Enter 5 Recently Served Customer Token Numbers:\n";

    for (int i = 0; i < 5; i++) {
      top++;  
      cin >> stack[top];
    }

    cout << "\nService History (Most Recent First):\n";
  
    while (top >= 0) {
        cout << "Token Number: " << stack[top] << endl;
        top--;
    }

    return 0;
}
