# [2492. Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)

## Solution
- You can use `DFS` or `BFS` to traverse the graph and find the minimum edge in any path that connect two cities `1` and `n`.

## Complexity
- **Time Complexity**: `O(nm)`, where `n` is the number of cities and `m` is the number of edges.
- **Space Complexity**: `O(n + m)`, for the adjacency list.

## Code
- **DFS-Solution**
```cpp
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
```
- **BFS-Solution**
```cpp
class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int> > > adj(n + 1); // To store the graph
        vector<bool> vis(n + 1, 0); // To mark the visited nodes

        for(auto & edge : roads) { // Build the graph
            auto [u, v, dist] = tie(edge[0], edge[1], edge[2]);
            adj[u].emplace_back(v, dist);
            adj[v].emplace_back(u, dist);
        }

        queue<int> q; // To store the nodes that should be processed
        q.emplace(1); // Start from node 1
        int ans = 1e5; // Put the answer with high value and minimize it while processing the nodes
        while(!q.empty()) {
            int curNode = q.front(); // Get the current node
            q.pop(); // Remove it from the queue
            vis[curNode] = 1; // Mark it as visited
            for(auto & edge : adj[curNode]) { // Traverse all the edges of the current node
                auto [nextNode, dist] = tie(edge.first, edge.second); // Get the next node and the distance
                ans = min(ans, dist); // Minimize the answer
                if(!vis[nextNode]) q.emplace(nextNode); // If the next node is not visited, add it to the queue
            }
        }
        return ans; // Return the answer
    }
};
```