# [1466. Reorder Routes to Make All Paths Lead to the City Zero](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)

## Solution
- Store the connections you have in a map.
- Apply `DFS` on the graph after storing it as an undirected graph.
- While exploring the graph, when you meet an edge that exist in the map, increment your answer, because it should be reversed.

## Complexity
- **Time Complexity**: `O((n + m) * log(n))`, where `n` is the number of nodes and `m` is the number of edges.
- **Space Complexity**: `O(n + m)`, for the adjacency list.

## Code
```cpp
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
```