#include <bits/stdc++.h>
using namespace std;

// Funda (Undirected Graph Cycle Detection – DFS)
// Cycle = Agar kisi node se DFS karte hue hum ek visited neighbour mil jaye jo current node ka parent na ho, to cycle hai.
// Kyunki undirected graph me edges dono taraf hote hain, isliye DFS me parent track karna padta hai, taaki hum usi edge ko dobara cycle na samjhein.

// Algorithm
// Har node ke liye check karo:

// Agar visited nahi → DFS call karo

// Agar DFS return kare true → cycle found

// DFS(node, parent):

// Mark node visited

// Har neighbour ke liye:

// Agar visited nahi → DFS(neighbour, node)

// Agar visited and neighbour != parent → cycle found

// DFS utility to check if a cycle exists from the current node
bool dfsCycleCheck(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for (int neighbour : adj[node]) {
        // Ignore the edge back to the parent
        if (neighbour == parent) 
            continue;

        // If neighbour is visited and not parent → cycle found
        if (visited[neighbour]) 
            return true;

        // If not visited, recurse
        if (dfsCycleCheck(neighbour, node, adj, visited)) 
            return true;
    }
    return false;
}

// Main function to detect cycle in undirected graph
bool isCyclic(vector<int> adj[], int V) {
    vector<bool> visited(V, false);

    // Check for each connected component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5; // number of vertices
    vector<int> adj[V];

    // Example graph edges
    adj[0] = {1};
    adj[1] = {0, 2, 4};
    adj[2] = {1, 3};
    adj[3] = {2, 4};
    adj[4] = {1, 3};

    if (isCyclic(adj, V))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle\n";

    return 0;
}
