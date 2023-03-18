# [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)

## Solution
- You can use any shortest path algorithm to calculate the distance from source `k` to all other nodes in the network.
- The constraints are small enough to use any algorithm.
- I will use the three most common algorithms: Dijkstra, Bellman-Ford, and Floyd-Warshall.

## Complexity
- **Time Complexity**:
    - **Dijkstra**: `O(E log V)`, where `E` is the number of edges and `V` is the number of vertices.
    - **Bellman-Ford**: `O(VE)`, where `E` is the number of edges and `V` is the number of vertices.
    - **Floyd-Warshall**: `O(V^3)`, where `V` is the number of vertices.
- **Space Complexity**:
    - **Dijkstra**: `O(V)`, where `V` is the number of vertices.
    - **Bellman-Ford**: `O(V)`, where `V` is the number of vertices.
    - **Floyd-Warshall**: `O(V^2)`, where `V` is the number of vertices.

## Code
- **Dijkstra**:
```cpp
class Solution {
public:
    vector<int> dis; // dis[i] = distance from source to node i

    void dijkstra(vector<vector<pair<int, int> > > &adj, int src) { // Apply Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq; // Use min heap to get the node with the smallest distance in O(log V)

        pq.emplace(0, src); // Push the source node into the min heap
        dis[src] = 0; // Mark the distance from source to source as 0

        while (!pq.empty()) {
            auto [oldDis, curNode] = pq.top();
            pq.pop();

            if (oldDis != dis[curNode]) continue; // If the distance from source to curNode is not the smallest, skip it

            for (const auto &neighbor: adj[curNode]) { // <neighbor, weight>
                if (dis[neighbor.first] > dis[curNode] + neighbor.second) {
                    dis[neighbor.first] = dis[curNode] + neighbor.second;
                    pq.emplace(dis[neighbor.first], neighbor.first);
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        dis = vector<int>(n + 1, 1e9);
        vector<vector<pair<int, int> > > adj(n + 1);

        for (const auto &i: times) { // Build the graph
            auto [u, v, w] = tie(i[0], i[1], i[2]);
            adj[u].emplace_back(v, w);
        }

        dijkstra(adj, k); // Apply Dijkstra's algorithm

        int ans = 0; // The maximum distance from source to any node
        for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
        return (ans < 1e9 ? ans : -1); // ans == 1e9 -> There is no path from source to a node in the graph.
    }
};
```
- **Bellman-Ford**:
```cpp
class Solution {
public:
    int n; // number of nodes
    const int oo = 1e9; // infinity
    vector<int> dist; // distance from source K
    vector<vector<pair<int, int> > > adj; // our graph

    void bellman(int src) { // apply bellman ford algorithm
        for(int i = 1; i < n; i++) {
            for(int srcNode = 1; srcNode <= n; srcNode++) {
                for(auto [destNode, w] : adj[srcNode]) {
                    dist[destNode] = min(dist[destNode], dist[srcNode] + w);
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        n = N;
        adj = vector<vector<pair<int, int> > > (n + 1);
        dist = vector<int> (n + 1, oo);
        dist[k] = 0; // distance from source K to K is 0

        for(auto i : times) { // build our graph
            auto [u, v, w] = tie(i[0], i[1], i[2]);
            adj[u].emplace_back(v, w);
        }

        bellman(k); // apply bellman ford algorithm
        int ans = dist[1]; // this variable will store the max distance from source K to any other node
        for(int i = 1; i <= n; i++) ans = max(ans, dist[i]); // find the max distance
        return (ans < oo) ? ans : -1; // if it's infinity -> no path so return -1 else return ans
    }
};
```

- **Floyd-Warshall**:
```cpp
class Solution {
public:
    void floyd(vector<vector<int> > &adj, int n) { // Floyd-Warshall Algorithm to find APSP
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > adj(n + 1, vector<int> (n + 1, 1e9)); // adj[i][j] = distance from node i to node j
        for(auto & i : times) // Build the graph
            adj[i[0]][i[1]] = i[2]; 

        for(int i = 1; i <= n; i++) adj[i][i] = 0; // Distance from node i to node i is 0

        floyd(adj, n + 1); // Apply Floyd-Warshall Algorithm
        
        int ans = 0;
        for (int i = 1; i <= n; i++) // Find the maximum distance from source to any node
            ans = max(ans, adj[k][i]);
        return ans == 1e9 ? -1 : ans; // ans == 1e9 -> There is no path from source to a node in the graph.
    }
};
```