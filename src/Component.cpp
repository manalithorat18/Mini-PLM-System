#include "../include/Component.h"

Component::Component() {
}

Component::Component(
    string id,
    string name,
    string version,
    string owner,
    string status
) {

    this->id = id;
    this->name = name;
    this->version = version;
    this->owner = owner;
    this->status = status;
}

string Component::getId() {
    return id;
}

string Component::getName() {
    return name;
}

string Component::getVersion() {
    return version;
}

string Component::getOwner() {
    return owner;
}

string Component::getStatus() {
    return status;
}

void Component::display() {

    cout << "\n====================================\n";
    cout << "Component Details\n";
    cout << "====================================\n";

    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Version: " << version << endl;
    cout << "Owner: " << owner << endl;
    cout << "Status: " << status << endl;
}