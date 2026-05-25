#ifndef DEPENDENCY_MANAGER_H
#define DEPENDENCY_MANAGER_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class DependencyManager {

private:

    unordered_map<string, vector<string>> graph;

    bool dfs(
        string node,
        unordered_map<string, bool>& visited,
        unordered_map<string, bool>& recStack
    );

public:

    void addDependency(string from, string to);

    void showDependencies();

    bool hasCycle();
};

#endif