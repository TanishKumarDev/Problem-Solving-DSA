#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Directed Graph Cycle Detection using DFS
class Solution {
  public:
    // Helper function to detect cycle using DFS in a directed graph
    bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {
            if (!visited[v]) {
                if (isCycleDFS(adj, v, visited, inRecursion)) {
                    return true;
                }
            } else if (inRecursion[v]) {
                return true;
            }
        }

        inRecursion[u] = false; // Backtrack
        return false;
    }

    // Main function to detect cycle in directed graph
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Convert edge list to adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // Directed edge
        }

        // Step 2: Visited and recursion arrays
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        // Step 3: Run DFS from every unvisited node
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (isCycleDFS(adj, i, visited, inRecursion)) {
                    return true;
                }
            }
        }

        return false; // No cycle found
    }
};
