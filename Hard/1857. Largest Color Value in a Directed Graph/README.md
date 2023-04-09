# [1857. Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/)

## Solution
- Use `DFS` to detect if there's a cycle in the graph
    - If there's a cycle return `-1`
- Use `Topological Sort` to process the ready nodes level by level
    - For every node, store the maximum color frequency of each color
    - Pass the maximum color frequency of each color to its children
    - If the node becomes ready, put it in the queue

## Complexity
- Time Complexity: `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
- Space Complexity: `O(V + E)`, for `adj`.

## Code
```cpp
class Solution {
public:
    vector<vector<int> > adj; // To build the graph
    vector<bool> vis; // To mark the visited nodes
    vector<bool> inStack; // To detect if there's a cycle in the graph

    void dfs(int node, bool &cycle) {
        vis[node] = true; // Mark the node as visited
        inStack[node] = true; // Put it in the stack

        for (auto & child: adj[node]) { // Go to the neighbors of the current node
            if (!vis[child])
                dfs(child, cycle);
            else if (inStack[child]) return cycle = true, void(); // Found in the stack -> There's a cycle
        }

        inStack[node] = false; // Remove it from the stack
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = (int) colors.size();
        vector<int> inDegree(n, 0); // Used to indicate the number of inner edges to every node
        queue<int> ready; // To process the ready nodes level by level -> <node, maxColor>
        int freq[n][26]; // Store the maximum color frequency of each node
        memset(freq, 0, sizeof freq); // Initialize the freq array with 0
        adj = vector<vector<int> > (n);
        vis = vector<bool> (n, false);
        inStack = vector<bool> (n, false);

        for(auto & i : edges) { // Build the graph
            auto [u, v] = tie(i[0], i[1]);
            adj[u].emplace_back(v);
            inDegree[v]++; // Increase the indegree of the vertex
        }

        bool cycle = false; // Variable to detect the cycle is found in the graph
        for (int node = 0; node < n; ++node) { // Loop through every node in graph
            if(!inDegree[node]) ready.emplace(node); // Put the ready node in the queue
            if(!vis[node]) dfs(node, cycle);
        }

        if(cycle) return -1; // Found cycle -> Return -1

        while(!ready.empty()) { // Start processing the ready nodes
            auto curNode = ready.front(); // Get the current ready node
            ready.pop(); // remove it from the queue

            freq[curNode][colors[curNode] - 'a']++; // Increase its color
            for(auto &child : adj[curNode]) { // Loop on its children
                for(int i = 0; i < 26; i++) // Pass the max frequency for every color to the child
                    freq[child][i] = max(freq[child][i], freq[curNode][i]);

                if(!--inDegree[child]) // Remove the edge [curNode -> child] and if it becomes ready put it in the queue
                    ready.emplace(child);
            }
        }

        int ans = 0;
        for (int node = 0; node < n; ++node) {
            for (int color = 0; color < 26; ++color) {
                ans = max(ans, freq[node][color]); // Loop through all colors for all nodes and maximize the answer
            }
        }
        return ans; // Return the maximum answer
    }
};
```