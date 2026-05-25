#ifndef VERSION_MANAGER_H
#define VERSION_MANAGER_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class VersionManager {

private:

    unordered_map<string, vector<string>> versionHistory;

public:

    void addVersion(
        string componentId,
        string version
    );

    void showVersions(string componentId);

    void rollbackVersion(string componentId);

    string getLatestVersion(string componentId);
};

#endif