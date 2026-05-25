#include "../include/VersionManager.h"

void VersionManager::addVersion(
    string componentId,
    string version
) {

    versionHistory[componentId].push_back(version);
}

void VersionManager::showVersions(
    string componentId
) {

    if (versionHistory.find(componentId)
        == versionHistory.end()) {

        cout << "\nNo Version History Found.\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "Version History\n";
    cout << "====================================\n";
    cout << "\nVersion History for "
         << componentId
         << ":\n";

    for (string version
        : versionHistory[componentId]) {

        cout << version << endl;
    }
}

void VersionManager::rollbackVersion(
    string componentId
) {

    if (versionHistory[componentId].size() <= 1) {

        cout << "\nRollback Not Possible.\n";
        return;
    }

    versionHistory[componentId].pop_back();

    cout << "\nRollback Successful.\n";
}

string VersionManager::getLatestVersion(
    string componentId
) {

    if (versionHistory.find(componentId)
        == versionHistory.end()) {

        return "No Version";
    }

    return versionHistory[componentId].back();
}