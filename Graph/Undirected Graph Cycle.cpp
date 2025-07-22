#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Undirected Graph Cycle Detection using DFS 
class Solution {
  public:
    // Helper function to check for cycle using DFS
    bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, int parent) {
        visited[u] = true;

        for (int &v : adj[u]) {
            // If neighbor is parent, skip it
            if (v == parent) continue;

            // If already visited, cycle detected
            if (visited[v]) return true;

            // DFS call for the neighbor
            if (isCycleDFS(adj, v, visited, u)) {
                return true;
            }
        }

        return false; // No cycle found in this DFS path
    }

    // Main function to check if the graph contains a cycle
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from edges
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }

        // Step 2: Visited array for DFS traversal
        vector<bool> visited(V, false);

        // Step 3: Run DFS from each unvisited node
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (isCycleDFS(adj, i, visited, -1)) {
                    return true; // Cycle found
                }
            }
        }

        return false; // No cycle in any component
    }
};


#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Undirected Graph Cycle Detection using BFS
class Solution {
  public:
    // Helper function to check for cycle using BFS
    bool isCycleBFS(vector<int> adj[], int start, vector<bool>& visited) {
        queue<pair<int, int>> q;  // {current_node, parent_node}
        visited[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int &neighbor : adj[node]) {
                // If not visited, push into queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                // If already visited and not parent, cycle found
                else if (neighbor != parent) {
                    return true;
                }
            }
        }

        return false;  // No cycle in this component
    }

    // Main function to check if the graph contains a cycle
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from edges
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }

        // Step 2: Visited array for BFS traversal
        vector<bool> visited(V, false);

        // Step 3: Run BFS from each unvisited node
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (isCycleBFS(adj, i, visited)) {
                    return true;  // Cycle detected
                }
            }
        }

        return false;  // No cycle in any component
    }
};
