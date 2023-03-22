class Solution {
public:
    vector<bool> vis; // Used to mark the visited nodes
    void dfs(vector<vector<pair<int, int> > > &adj, int node, int &mn) { // DFS function to traverse the graph and get the minimum edge cost
        if(vis[node]) return; // If the node is already visited, return
        vis[node] = true; // Mark the node as visited

        for(auto & [v, dist] : adj[node]) { // Traverse the adjacent nodes
            mn = min(mn, dist); // Update the minimum edge cost
            dfs(adj, v, mn); // Recursively call the DFS function to traverse the adjacent nodes
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int> > > adj(n + 1); // Adjacency list to store the graph
        vis = vector<bool> (n + 1, 0); // Mark all the nodes as unvisited

        for(auto & edge : roads) { // Build the graph
            auto [u, v, dist] = tie(edge[0], edge[1], edge[2]);
            adj[u].emplace_back(v, dist);
            adj[v].emplace_back(u, dist);
        }

        int ans = 1e5; // Store the answer
        dfs(adj, 1, ans); // Call the DFS function to traverse the graph and get the minimum edge cost
        return ans; // Return the answer
    }
};