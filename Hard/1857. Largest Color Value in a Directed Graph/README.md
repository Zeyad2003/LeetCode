# [1857. Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/)

## Solution
- Use `DFS` to detect if there is a cycle in the graph, if there is a cycle, return `-1`.
- Use `Topological Sort` to get the order of the nodes, and pass the answer for every node to its children.
- Loop through the order of the nodes, and update the answer for every node to get the maximum answer.

## Complexity
- **Time Complexity**: `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
- **Space Complexity**: `O(V + E)`, for the adjacency list.

## Code
```cpp
class Solution {
public:
    bool cycle = false; // used to detect if we have a cycle in the graph

    void dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &recStack, int node) {
        visited[node] = true;
        recStack[node] = true;

        for (int child: adj[node]) {
            if (!visited[child])
                dfs(adj, visited, recStack, child);
            else if (recStack[child]) return cycle = true, void();
        }

        recStack[node] = false;
    }



    int largestPathValue(string colors, vector<vector<int>> &edges) {
        int n = (int) colors.size();
        vector<vector<int> > adj(n);
        vector<int> inDegree(n, 0); // used to calculate the in-degree of each node when we build the graph

        for (auto &it: edges) { // build the graph
            auto[u, v] = tie(it[0], it[1]);
            adj[u].emplace_back(v);
            inDegree[v]++;
        }

        vector<bool> visited(n, false); // used to mark the visited nodes
        vector<bool> recStack(n, false); // used to detect if we have a cycle in the graph
        for (int node = 0; node < n; node++)
            if (!visited[node])
                dfs(adj, visited, recStack, node); // run dfs and check if the graph has a cycle

        if (cycle) return -1; // if the graph has a cycle -> return -1

        queue<int> ready;
        for (int node = 0; node < n; node++) // put the nodes with in-degree = 0 in the queue to apply top-sort
            if (!inDegree[node])
                ready.emplace(node);

        vector<vector<int> > store(n, vector<int> (26, 0)); // store[i][j] = the number of nodes with color j in the path from node 0 to node i
        while(!ready.empty()) {
            auto curNode = ready.front(); // get the current node
            ready.pop(); // remove it from the queue
            store[curNode][colors[curNode] - 'a']++; // increase the number of nodes with color colors[curNode] in the path from node 0 to node curNode
           
            for(auto & child : adj[curNode]) { // loop on the children of the current node
                for(int i = 0; i < 26; i++) // loop on all colors
                    store[child][i] = max(store[child][i], store[curNode][i]); // update the number of nodes with color i in the path from node 0 to node child
                if(!--inDegree[child]) // if the in-degree of the child becomes 0 -> put it in the queue
                    ready.emplace(child);
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i++) // loop on all nodes and get the color that appears the most in the path from node 0 to node i
            ret = max(ret, *max_element(store[i].begin(), store[i].end()));
        return ret; // return the answer
    }
};
```