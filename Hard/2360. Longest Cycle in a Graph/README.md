# [2360. Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/)

## Solution
- Use `Topological Sort`, to keep removing the nodes until the remaining nodes will cause cycles.
- Then use `DFS` to count the number of nodes in this cycle and maximize the answer for every cycle.

## Complexity
- Time complexity: `O(n)` where n is the length of `edges` vector.
- Space complexity: `O(n)`, for the visited vector.

## Code
``` cpp
class Solution {
public:
    vector<int> inDegree; // Used to see the incoming edges for every node
    vector<bool> vis; // Used to mark every node we visited when applying DFS

    int dfs(vector<int> &edges, int node) { // Count the number of nodes you go through to reach back again
        if(vis[node]) return 0; // Reach back
        vis[node] = true; // Mark as visited
        return 1 + dfs(edges, edges[node]); // Go to next node
    }

    int longestCycle(vector<int> &edges) {
        int n = (int) edges.size();
        inDegree = vector<int> (n, 0);
        vis = vector<bool> (n, false);

        for(int i = 0; i < n; i++) // Count every incoming edge to a specific node
            if(~edges[i])
                inDegree[edges[i]]++;

        queue<int> q;
        for(int node = 0; node < n; node++) // For all nodes with no incoming edges -> Put them in the queue
            if(!inDegree[node])
                q.emplace(node);

        while(!q.empty()) { // Keep Exploring, when you meet a cycle -> the queue will be empty
            auto curNode = q.front();
            q.pop();

            int child = edges[curNode];
            if(~child and !--inDegree[child])
                q.emplace(child);
        }

        int ans = -1; // Initialize with -1 as no cycles found until now
        for(int i = 0; i < n; i++) // For every node from 0 to n - 1
            if(inDegree[i] and !vis[i]) // If the node has incoming edge and !visited -> the node in a cycle
                ans = max(ans, dfs(edges, i)); // Get the length of the cycle and maximize the answer

        return ans; // Return the answer
    }
};
```