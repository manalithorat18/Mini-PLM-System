#include "../include/DependencyManager.h"

void DependencyManager::addDependency(
    string from,
    string to
) {

    graph[from].push_back(to);
}

void DependencyManager::showDependencies() {

    cout << "\n===== Dependency Graph =====\n";

    for (auto pair : graph) {

        cout << pair.first << " -> ";

        for (string dependency : pair.second) {
            cout << dependency << " ";
        }

        cout << endl;
    }
}

bool DependencyManager::dfs(
    string node,
    unordered_map<string, bool>& visited,
    unordered_map<string, bool>& recStack
) {

    visited[node] = true;
    recStack[node] = true;

    for (string neighbor : graph[node]) {

        if (!visited[neighbor]) {

            if (dfs(neighbor, visited, recStack))
                return true;
        }

        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;

    return false;
}

bool DependencyManager::hasCycle() {

    unordered_map<string, bool> visited;
    unordered_map<string, bool> recStack;

    for (auto pair : graph) {

        if (!visited[pair.first]) {

            if (dfs(pair.first, visited, recStack))
                return true;
        }
    }

    return false;
}