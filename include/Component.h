#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
using namespace std;

class Component {

private:
    string id;
    string name;
    string version;
    string owner;
    string status;

public:

    // Default Constructor
    Component();

    // Parameterized Constructor
    Component(
        string id,
        string name,
        string version,
        string owner,
        string status
    );

    // Getter Functions
    string getId();
    string getName();
    string getVersion();
    string getOwner();
    string getStatus();

    // Display Function
    void display();
};

#endif