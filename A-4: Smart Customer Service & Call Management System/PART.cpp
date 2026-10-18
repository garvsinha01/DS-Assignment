
#include <iostream>
#include <string>
using namespace std;

string calls[100];
int front = 0, rear = -1;

string history[100];
int top = -1;

string urgent[100];
int urgentCount = 0;

void addCall() {
    if (rear == 99) {
        cout << "Queue is full!\n";
        return;
    }

    cin.ignore(1000, '\n');
    cout << "Enter customer request: ";
    getline(cin, calls[++rear]);

    cout << "Call added successfully!\n";
}

void handleCall() {
    if (front > rear) {
        cout << "No calls waiting!\n";
        return;
    }

    cout << "Handling: " << calls[front] << "\n";

    if (top < 99)
        history[++top] = calls[front];

    front++;
}

void addUrgent() {
    if (urgentCount == 100) {
        cout << "Priority queue is full!\n";
        return;
    }

    cin.ignore(1000, '\n');
    cout << "Enter urgent request: ";
    getline(cin, urgent[urgentCount++]);

    cout << "Urgent request added!\n";
}

void handleUrgent() {
    if (urgentCount == 0) {
        cout << "No urgent requests!\n";
        return;
    }

    cout << "Handling urgent request: " << urgent[0] << "\n";

    if (top < 99)
        history[++top] = urgent[0];

    for (int i = 0; i < urgentCount - 1; i++)
        urgent[i] = urgent[i + 1];

    urgentCount--;
}

void viewHistory() {
    if (top == -1) {
        cout << "No resolved requests!\n";
        return;
    }

    cout << "\nResolved Requests:\n";

    for (int i = top; i >= 0; i--)
        cout << history[i] << "\n";
}

void IVR() {
    int choice;

    cout << "\n--- CUSTOMER IVR ---\n";
    cout << "1. Billing Support\n";
    cout << "2. Technical Support\n";
    cout << "3. Account Support\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 0)
        return;

    switch (choice) {
        case 1: cout << "Billing Support selected.\n"; break;
        case 2: cout << "Technical Support selected.\n"; break;
        case 3: cout << "Account Support selected.\n"; break;
        default: cout << "Invalid choice!\n";
    }

    IVR();
}

int main() {
    int choice;

    do {
        cout << "\n===== CUSTOMER SERVICE SYSTEM =====\n";
        cout << "1. Add Normal Call\n";
        cout << "2. Handle Normal Call\n";
        cout << "3. Add Urgent Request\n";
        cout << "4. Handle Urgent Request\n";
        cout << "5. View Resolved History\n";
        cout << "6. Open IVR Menu\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCall(); break;
            case 2: handleCall(); break;
            case 3: addUrgent(); break;
            case 4: handleUrgent(); break;
            case 5: viewHistory(); break;
            case 6: IVR(); break;
            case 7: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
