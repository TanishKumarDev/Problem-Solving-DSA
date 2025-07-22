#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // Recursive function to perform DFS traversal
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;              // Mark the current node as visited
        ls.push_back(node);         // Store the current node in the traversal list

        // Visit all the unvisited neighbours of the current node
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);  // Recursive DFS call for the neighbour
            }
        }
    }

  public:
    // Main function to return DFS traversal of the entire graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};       // Visited array to track visited nodes
        int start = 0;          // Usually, DFS starts from node 0 (as per problem statement)
        vector<int> ls;         // List to store the DFS traversal result

        dfs(start, adj, vis, ls);   // Start DFS traversal from node 0
        return ls;                  // Return the final DFS traversal path
    }
};

// Utility function to add an undirected edge between nodes u and v
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);   // Add v to u's adjacency list
    adj[v].push_back(u);   // Add u to v's adjacency list (because undirected)
}

// Utility function to print the final DFS traversal result
void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    // Creating an adjacency list for a graph with 5 vertices (0 to 4)
    vector<int> adj[5];

    // Add edges to the undirected graph
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    // Call DFS and get traversal starting from node 0
    vector<int> ans = obj.dfsOfGraph(5, adj);

    // Print the DFS traversal
    printAns(ans);

    return 0;
}