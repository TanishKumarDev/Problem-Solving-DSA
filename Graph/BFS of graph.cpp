// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();                 // Get number of vertices
        vector<int> vis(V, 0);              // Visited array initialized to 0
        vector<int> result;                 // Store BFS traversal result
        queue<int> q;                       // Queue for BFS

        // Start BFS from node 0
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);         // Add current node to result

            // Visit all unvisited neighbors
            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    q.push(neighbor);       // Push unvisited neighbor to queue
                    vis[neighbor] = 1;      // Mark as visited
                }
            }
        }

        return result;
    }
};
