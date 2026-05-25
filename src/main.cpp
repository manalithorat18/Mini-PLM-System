#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/Logger.h"
#include "../include/VersionManager.h"
#include "../include/DependencyManager.h"
#include "../include/Component.h"

using namespace std;

vector<Component> components;
DependencyManager dependencyManager;
VersionManager versionManager;
void addComponent();
void displayComponents();
void searchComponent();
void updateComponent();
void deleteComponent();
void saveToFile();
void loadFromFile();
void addDependency();
void showDependencies();
void checkCircularDependency();
void addVersion();
void showVersions();
void rollbackVersion();
void showLatestVersion();
void showAnalytics();
void filterByStatus();
void exportReport();
void printHeader(string title);

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

    Logger::log(
        "Component Added: " + id);
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

            Logger::log(
                "Component Updated: " + searchId);

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

            Logger::log(
                "Component Deleted: " + searchId);

            return;
        }
    }

    cout << "\nComponent Not Found.\n";
}

void saveToFile() {

    ofstream file("data/components.txt");

    if (!file) {

        cout << "\nError Opening File.\n";
        return;
    }

    for (Component c : components) {

        file
            << c.getId() << ","
            << c.getName() << ","
            << c.getVersion() << ","
            << c.getOwner() << ","
            << c.getStatus() << endl;
    }

    file.close();

    cout << "\nData Saved Successfully.\n";
}

void loadFromFile() {

    ifstream file("data/components.txt");

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        string id;
        string name;
        string version;
        string owner;
        string status;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, version, ',');
        getline(ss, owner, ',');
        getline(ss, status, ',');

        components.push_back(
            Component(
                id,
                name,
                version,
                owner,
                status
            )
        );
    }

    file.close();
}

void addDependency() {

    string from;
    string to;

    cout << "\nEnter Parent Component: ";
    cin >> from;

    cout << "Enter Dependency Component: ";
    cin >> to;

    dependencyManager.addDependency(from, to);

    cout << "\nDependency Added Successfully.\n";

    Logger::log(
        "Dependency Added: " + from + " -> " + to);
}

void showDependencies() {

    dependencyManager.showDependencies();
}

void checkCircularDependency() {

    if (dependencyManager.hasCycle()) {

        cout << "\nCircular Dependency Detected!\n";
    }

    else {

        cout << "\nNo Circular Dependency Found.\n";
    }
}

void addVersion() {

    string componentId;
    string version;

    cout << "\nEnter Component ID: ";
    cin >> componentId;

    cout << "Enter Version: ";
    cin >> version;

    versionManager.addVersion(
        componentId,
        version
    );

    cout << "\nVersion Added Successfully.\n";
}

void showVersions() {

    string componentId;

    cout << "\nEnter Component ID: ";
    cin >> componentId;

    versionManager.showVersions(componentId);
}

void rollbackVersion() {

    string componentId;

    cout << "\nEnter Component ID: ";
    cin >> componentId;

    versionManager.rollbackVersion(componentId);
}

void showLatestVersion() {

    string componentId;

    cout << "\nEnter Component ID: ";
    cin >> componentId;

    cout << "\nLatest Version: "
         << versionManager.getLatestVersion(componentId)
         << endl;
}

void showAnalytics() {

    printHeader("Analytics Dashboard");

    cout << "Total Components: "
         << components.size()
         << endl;

    int approved = 0;
    int pending = 0;

    for (Component c : components) {

        if (c.getStatus() == "Approved")
            approved++;

        else
            pending++;
    }

    cout << "Approved Components: "
         << approved
         << endl;

    cout << "Pending Components: "
         << pending
         << endl;
}

void filterByStatus() {

    string status;

    cout << "\nEnter Status: ";
    cin >> status;

    bool found = false;

    for (Component c : components) {

        if (c.getStatus() == status) {

            c.display();
            found = true;
        }
    }

    if (!found) {

        cout << "\nNo Matching Components Found.\n";
    }
}

void exportReport() {

    ofstream file("data/report.txt");

    if (!file) {

        cout << "\nError Creating Report.\n";
        return;
    }

    file << "====================================\n";
    file << "MINI PLM REPORT\n";
    file << "====================================\n\n";

    file << "Total Components: "
         << components.size()
         << "\n\n";

    for (Component c : components) {

        file << "ID: "
             << c.getId()
             << endl;

        file << "Name: "
             << c.getName()
             << endl;

        file << "Version: "
             << c.getVersion()
             << endl;

        file << "Owner: "
             << c.getOwner()
             << endl;

        file << "Status: "
             << c.getStatus()
             << endl;

        file << "---------------------\n";
    }

    file.close();

    cout << "\nReport Exported Successfully.\n";
}

void printHeader(string title) {

    cout << "\n====================================\n";

    cout << title << endl;

    cout << "====================================\n";
}


int main() {
    loadFromFile();

    int choice;

    while (true) {

        printHeader("Mini PLM System");

        cout << "1. Add Component\n";
        cout << "2. Display Components\n";
        cout << "3. Search Component\n";
        cout << "4. Update Component\n";
        cout << "5. Delete Component\n";
        cout << "6. Save Data\n";
        cout << "7. Add Dependency\n";
        cout << "8. Show Dependencies\n";
        cout << "9. Check Circular Dependency\n";
        cout << "10. Add Version\n";
        cout << "11. Show Version History\n";
        cout << "12. Rollback Version\n";
        cout << "13. Show Latest Version\n";
        cout << "14. Analytics Dashboard\n";
        cout << "15. Filter By Status\n";
        cout << "16. Export Report\n";
        cout << "17. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        try
        {
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
                saveToFile();
                break;

            case 7:
                addDependency();
                break;

            case 8:
                showDependencies();
                break;

            case 9:
                checkCircularDependency();
                break;

            case 10:
                addVersion();
                break;

            case 11:
                showVersions();
                break;

            case 12:
                rollbackVersion();
                break;

            case 13:
                showLatestVersion();
                break;

            case 14:
                showAnalytics();
                break;

            case 15:
                filterByStatus();
                break;

            case 16:
                exportReport();
                break;

            case 17:
                cout << "\nExiting Program...\n";
                return 0;

            default:
                cout << "\nInvalid Choice.\n";
            }
        }

        catch (exception &e)
        {

            cout << "\nException Occurred: "
                 << e.what()
                 << endl;
        }
    }

    return 0;
}