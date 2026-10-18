
#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id, quantity;
    string name, category, expiry;
    float price;
};

Product p[100];
int n = 0;

void add() {
    cout << "Enter ID: ";
    cin >> p[n].id;

    cout << "Enter Name: ";
    cin >> p[n].name;

    cout << "Enter Category: ";
    cin >> p[n].category;

    cout << "Enter Price: ";
    cin >> p[n].price;

    cout << "Enter Quantity: ";
    cin >> p[n].quantity;

    cout << "Enter Expiry (YYYY-MM-DD): ";
    cin >> p[n].expiry;

    n++;
    cout << "Product added!\n";
}

void display() {
    for (int i = 0; i < n; i++) {
        cout << "\nID: " << p[i].id;
        cout << "\nName: " << p[i].name;
        cout << "\nCategory: " << p[i].category;
        cout << "\nPrice: " << p[i].price;
        cout << "\nQuantity: " << p[i].quantity;
        cout << "\nExpiry: " << p[i].expiry << "\n";
    }
}

void search() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (p[i].id == id) {
            cout << "Product found: " << p[i].name
                 << ", Price: " << p[i].price << "\n";
            return;
        }
    }

    cout << "Product not found!\n";
}

void update() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (p[i].id == id) {
            cout << "Enter new Price: ";
            cin >> p[i].price;

            cout << "Enter new Quantity: ";
            cin >> p[i].quantity;

            cout << "Product updated!\n";
            return;
        }
    }

    cout << "Product not found!\n";
}

void deleteProduct() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (p[i].id == id) {
            for (int j = i; j < n - 1; j++)
                p[j] = p[j + 1];

            n--;
            cout << "Product deleted!\n";
            return;
        }
    }

    cout << "Product not found!\n";
}

void sortPrice() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].price > p[j + 1].price)
                swap(p[j], p[j + 1]);
        }
    }

    display();
}

void sortQuantity() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].quantity > p[j + 1].quantity)
                swap(p[j], p[j + 1]);
        }
    }

    display();
}

void sortExpiry() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].expiry > p[j + 1].expiry)
                swap(p[j], p[j + 1]);
        }
    }

    display();
}

int main() {
    int choice;

    do {
        cout << "\n--- GROCERY INVENTORY ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Sort by Price\n";
        cout << "7. Sort by Quantity\n";
        cout << "8. Sort by Expiry\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteProduct(); break;
            case 6: sortPrice(); break;
            case 7: sortQuantity(); break;
            case 8: sortExpiry(); break;
            case 9: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    return 0;
}
