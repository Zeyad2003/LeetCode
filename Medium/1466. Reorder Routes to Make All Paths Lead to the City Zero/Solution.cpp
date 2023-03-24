class Solution {
public:
    map<pair<int, int>, bool> mp; // Store the connections we have
    vector<vector<int> > adj; // Store our graph
    vector<bool> vis; // Mark the visited nodes

    void dfs(int node, int &ans) { // Explore the graph
        vis[node] = true; // Mark the node as visited

        for(auto &child : adj[node]) {
            if(!vis[child]) { // If the node isn't visited
                ans += mp[{node, child}]; // Increment the ans if there is a connection because we will need to reverse it
                dfs(child, ans); // Explore the child
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        adj = vector<vector<int> > (n); // Initialize the graph with n nodes
        vis = vector<bool> (n, false); // Initialize the visited array with false

        for(auto &edge : connections) { // Build the graph and mark the connections we have
            auto [u, v] = tie(edge[0], edge[1]);
            mp[{u, v}] = true;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int ans = 0; // Initialize the answer
        dfs(0, ans); // Explore the graph and get the answer
        return ans; // Return the answer
    }
};