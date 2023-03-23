class Solution {
public:
    vector<bool> vis; // Mark visited nodes

    void dfs(vector<vector<int> > &adj, int node) { // Explore every connected component
        vis[node] = true;

        for(auto & child : adj[node]) {
            if(!vis[child]) {
                dfs(adj, child);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = (int) connections.size(); // Number of edges
        if(sz < n - 1) return -1; // If number of edges is less than n - 1, then we can't connect all the nodes
        vis = vector<bool> (n, false); // Initialize visited array with false
        vector<vector<int> > adj(n); // Adjacency list to store the graph

        for(auto & i : connections) { // Build the graph
            auto [u, v] = tie(i[0], i[1]);
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int numberOfConnected = 0; // This variable will store the number of connected components
        for (int i = 0; i < n; ++i) { // Loop through all the nodes
            if(!vis[i]) { // If the node is not visited, then it is a new connected component
                dfs(adj, i); // Explore the connected component
                numberOfConnected++; // Increment the number of connected components
            }
        }

        return numberOfConnected - 1; // To connect n nodes you need at least n - 1 edges, so the minimum will be numberOfConnected - 1
    }
};