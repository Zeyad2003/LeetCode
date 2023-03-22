# [2581. Count Number of Possible Root Nodes](https://leetcode.com/problems/count-number-of-possible-root-nodes/)

## Solution
- Count the number of valid guesses when 0 is the root node.
- Then traverse the tree and for every step you just need to change the answer you got from zero and remove the edge between `[parent, child]`, then use the edge between `[child, parent]`.
## Complexity
- **Time Complexity**: `O(nlog(n))`, where is the number of nodes in the tree, and `log(n)` -> for the map.
- **Space Complexity**: `O(n * m)`, for storing the graph in adjacency list.

## Code
```cpp
class Solution {
public:
    map<pair<int, int>, bool> dp; // dp[{u, v}] = true if u is the parent of v.
    vector<bool> vis; // Used to mark visited nodes.

    int getAns(vector<vector<int> > &adj, int node) { // Returns the number of correct guesses when assign zero as a root.
        vis[node] = true; // Mark the node as visited.
        int ans = 0; // Stores the number of correct guesses.
        for(auto &child : adj[node]) // Traverse all the tree
            if(!vis[child])
                ans += dp[{node, child}] + getAns(adj, child); // If the guess is correct, then add 1 to the answer.

        return ans; // Return the answer.
    }

    void dfs(vector<vector<int> > &adj, int node, int k, int ans, int &ret) { // Used to count the number of nodes that can be the root.
        vis[node] = true; // Mark the node as visited.
        if(ans >= k) ret++; // If the number of correct guesses is greater than or equal to k, then increment the answer.

        for(auto &child : adj[node])
            if(!vis[child])
                dfs(adj, child, k, ans - dp[{node, child}] + dp[{child, node}], ret); // Update the guess by remove [parent -> child] and add [child -> parent].
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = (int) edges.size(); n++; // Get the size of the nodes 0 -> n - 1, then increase to use when indexing.
        vector<vector<int> > graph(n); // Stores the tree.
        vis = vector<bool>(n, false); // Initialize the visited array.

        for(auto &edge: edges) { // Build the tree.
            auto [u, v] = tie(edge[0], edge[1]);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(auto &guess: guesses) { // Mark the guesses.
            auto [u, v] = tie(guess[0], guess[1]);
            dp[{u, v}] = true;
        }

        int ans = getAns(graph, 0); // Get the number of correct guesses when assign zero as a root.
        int ret = 0; // Stores the number of nodes that can be the root.
        vis = vector<bool>(n, false); // Reset the visited array.
        dfs(graph, 0, k, ans, ret); // Count the number of nodes that can be the root.
        return ret; // Return the answer.
    }
};
```