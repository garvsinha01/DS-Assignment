#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string course;
    Student* next;
};

class University {
    Student* head;
    Student* hashTable[10];

    int hashFunction(int rollNo) {
        return rollNo % 10;
    }

public:
    University() {
        head = NULL;

        for (int i = 0; i < 10; i++) {
            hashTable[i] = NULL;
        }
    }

    void registerStudent(int rollNo, string name) {
        if (searchStudent(rollNo) != NULL) {
            cout << "Student already exists.\n";
            return;
        }

        Student* newStudent = new Student;
        newStudent->rollNo = rollNo;
        newStudent->name = name;
        newStudent->course = "Not Enrolled";
        newStudent->next = head;
        head = newStudent;

        int index = hashFunction(rollNo);
        newStudent->next = head == newStudent ? NULL : newStudent->next;

        Student* hashNode = new Student;
        hashNode->rollNo = rollNo;
        hashNode->name = name;
        hashNode->course = "Not Enrolled";
        hashNode->next = hashTable[index];
        hashTable[index] = hashNode;

        cout << "Student registered successfully.\n";
    }

    Student* searchStudent(int rollNo) {
        int index = hashFunction(rollNo);
        Student* temp = hashTable[index];

        while (temp != NULL) {
            if (temp->rollNo == rollNo)
                return temp;
            temp = temp->next;
        }

        return NULL;
    }

    void updateStudent(int rollNo, string newName) {
        Student* temp = searchStudent(rollNo);

        if (temp == NULL) {
            cout << "Student not found.\n";
            return;
        }

        temp->name = newName;

        Student* current = head;
        while (current != NULL) {
            if (current->rollNo == rollNo)
                current->name = newName;
            current = current->next;
        }

        cout << "Student information updated.\n";
    }

    void enrollCourse(int rollNo, string course) {
        Student* temp = searchStudent(rollNo);

        if (temp == NULL) {
            cout << "Student not found.\n";
            return;
        }

        temp->course = course;

        Student* current = head;
        while (current != NULL) {
            if (current->rollNo == rollNo)
                current->course = course;
            current = current->next;
        }

        cout << "Course enrolled successfully.\n";
    }

    void withdrawCourse(int rollNo) {
        Student* temp = searchStudent(rollNo);

        if (temp == NULL) {
            cout << "Student not found.\n";
            return;
        }

        temp->course = "Not Enrolled";

        Student* current = head;
        while (current != NULL) {
            if (current->rollNo == rollNo)
                current->course = "Not Enrolled";
            current = current->next;
        }

        cout << "Course withdrawn successfully.\n";
    }

    void removeStudent(int rollNo) {
        Student* temp = head;
        Student* prev = NULL;

        while (temp != NULL && temp->rollNo != rollNo) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Student not found.\n";
            return;
        }

        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;

        int index = hashFunction(rollNo);
        Student* current = hashTable[index];
        Student* previous = NULL;

        while (current != NULL && current->rollNo != rollNo) {
            previous = current;
            current = current->next;
        }

        if (current != NULL) {
            if (previous == NULL)
                hashTable[index] = current->next;
            else
                previous->next = current->next;

            delete current;
        }

        cout << "Student record removed successfully.\n";
    }

    void displayStudents() {
        Student* temp = head;

        if (temp == NULL) {
            cout << "No student records available.\n";
            return;
        }

        while (temp != NULL) {
            cout << "\nRoll Number: " << temp->rollNo;
            cout << "\nName: " << temp->name;
            cout << "\nCourse: " << temp->course << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    University u;
    int choice, rollNo;
    string name, course;

    do {
        cout << "\n1. Register Student";
        cout << "\n2. Update Student";
        cout << "\n3. Enroll Course";
        cout << "\n4. Withdraw Course";
        cout << "\n5. Remove Student";
        cout << "\n6. Search Student";
        cout << "\n7. Display Students";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin >> name;
            u.registerStudent(rollNo, name);
            break;

        case 2:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            cout << "Enter New Name: ";
            cin >> name;
            u.updateStudent(rollNo, name);
            break;

        case 3:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            cout << "Enter Course: ";
            cin >> course;
            u.enrollCourse(rollNo, course);
            break;

        case 4:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            u.withdrawCourse(rollNo);
            break;

        case 5:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            u.removeStudent(rollNo);
            break;

        case 6: {
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            Student* s = u.searchStudent(rollNo);

            if (s != NULL) {
                cout << "Name: " << s->name;
                cout << "\nCourse: " << s->course << "\n";
            } else {
                cout << "Student not found.\n";
            }
            break;
        }

        case 7:
            u.displayStudents();
            break;

        case 8:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } 
    while (choice != 8);
    
    return 0;
}
