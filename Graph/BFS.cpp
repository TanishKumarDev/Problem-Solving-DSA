#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the Breadth First Traversal of a graph starting from node 0
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Step 1: Initialize visited array to keep track of visited nodes
        int vis[V] = {0}; 
        vis[0] = 1; // mark the starting node (0) as visited

        // Step 2: Use a queue for BFS traversal
        queue<int> q;
        q.push(0); // enqueue the starting node

        // Step 3: Vector to store BFS traversal result
        vector<int> bfs; 

        // Step 4: Traverse the graph using BFS
        while (!q.empty()) {
            int node = q.front(); 
            q.pop(); // dequeue the current node
            bfs.push_back(node); // store the visited node

            // Visit all unvisited neighbors of the current node
            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;      // mark as visited
                    q.push(neighbor);       // enqueue neighbor
                }
            }
        }

        return bfs; // return the BFS traversal
    }
};

// Utility function to add an undirected edge between two nodes
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);  // add v to u's list
    adj[v].push_back(u);  // add u to v's list (undirected graph)
}

// Utility function to print the traversal result
void printAns(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vector<int> adj[6];  // adjacency list for 6 vertices (0 to 5)

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    // Create a Solution object and perform BFS traversal
    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj);

    // Print the result
    printAns(ans);

    return 0;
}
