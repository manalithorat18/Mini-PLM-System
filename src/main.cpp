#include <iostream>
#include <vector>

#include "../include/Component.h"

using namespace std;

vector<Component> components;

void addComponent() {

    string id;
    string name;
    string version;
    string owner;
    string status;

    cout << "\nEnter Component ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Version: ";
    cin >> version;

    cout << "Enter Owner: ";
    cin >> owner;

    cout << "Enter Status: ";
    cin >> status;

    Component c(
        id,
        name,
        version,
        owner,
        status
    );

    components.push_back(c);

    cout << "\nComponent Added Successfully!\n";
}

void displayComponents() {

    if (components.empty()) {

        cout << "\nNo Components Found.\n";
        return;
    }

    for (Component c : components) {
        c.display();
    }
}

int main() {

    int choice;

    while (true) {

        cout << "\n========== Mini PLM ==========\n";

        cout << "1. Add Component\n";
        cout << "2. Display Components\n";
        cout << "3. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addComponent();
                break;

            case 2:
                displayComponents();
                break;

            case 3:
                cout << "\nExiting Program...\n";
                return 0;

            default:
                cout << "\nInvalid Choice.\n";
        }
    }

    return 0;
}