// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
    
  private: 
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& result){
        vis[node] = 1; // make current node as visited
        result.push_back(node); // add node to result(DFS order)
        
        // visit all unvisited neighbors
        for(int neighbor : adj[node]){
            if(!vis[neighbor]){
                dfsHelper(neighbor, adj, vis, result);
            }
        }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();  // total no of vertices
        vector<int> vis(v, 0); // visited array
        vector<int> result; // store DFS traversal
        
        dfsHelper(0, adj, vis, result); 
        
        return result;
        
    }
};