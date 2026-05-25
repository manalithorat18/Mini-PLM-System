#include <iostream>
#include <vector>

#include "../include/Component.h"

using namespace std;

vector<Component> components;
void addComponent();
void displayComponents();
void searchComponent();
void updateComponent();
void deleteComponent();

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

void searchComponent() {

    string searchId;

    cout << "\nEnter Component ID to Search: ";
    cin >> searchId;

    bool found = false;

    for (Component c : components) {

        if (c.getId() == searchId) {

            c.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nComponent Not Found.\n";
    }
}

void updateComponent() {

    string searchId;

    cout << "\nEnter Component ID to Update: ";
    cin >> searchId;

    for (Component &c : components) {

        if (c.getId() == searchId) {

            string name;
            string version;
            string owner;
            string status;

            cout << "Enter New Name: ";
            cin >> name;

            cout << "Enter New Version: ";
            cin >> version;

            cout << "Enter New Owner: ";
            cin >> owner;

            cout << "Enter New Status: ";
            cin >> status;

            c = Component(
                searchId,
                name,
                version,
                owner,
                status
            );

            cout << "\nComponent Updated Successfully.\n";

            return;
        }
    }

    cout << "\nComponent Not Found.\n";
}

void deleteComponent() {

    string searchId;

    cout << "\nEnter Component ID to Delete: ";
    cin >> searchId;

    for (int i = 0; i < components.size(); i++) {

        if (components[i].getId() == searchId) {

            components.erase(components.begin() + i);

            cout << "\nComponent Deleted Successfully.\n";

            return;
        }
    }

    cout << "\nComponent Not Found.\n";
}

int main() {

    int choice;

    while (true) {

        cout << "\n========== Mini PLM ==========\n";

        cout << "1. Add Component\n";
        cout << "2. Display Components\n";
        cout << "3. Search Component\n";
        cout << "4. Update Component\n";
        cout << "5. Delete Component\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            addComponent();
            break;

        case 2:
            displayComponents();
            break;

        case 3:
            searchComponent();
            break;

        case 4:
            updateComponent();
            break;

        case 5:
            deleteComponent();
            break;

        case 6:
            cout << "\nExiting Program...\n";
            return 0;
        }
    }

    return 0;
}