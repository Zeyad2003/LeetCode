# [1786. Number of Restricted Paths From First to Last Nodex](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/)

## Solution
- You have 2 separate problems here:
  - Find the shortest path from node n to all other nodes.
  - Find the number of paths from node 1 to node n, such that the every node you go through must have a distance less than the distance of the previous node.
## Complexity
- Time Complexity: `O(nlog(n))`, where `n` is the number of nodes.

- Space Complexity: `O(n + m)`, where m is the number of edges.

## Code
```cpp
class Solution {
public:
    vector<long long> dis; // Stores the distance from the source to each node
    const static int M = 1e9 + 7, N = 2e4 + 5;
    int dp[N]; // dp[i] = the number of ways to reach n from 1 using restricted paths

    void dijkstra(vector<vector<pair<int, int> > > &adj, int src) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<> > pq; // min heap to get the node with the minimum distance

        pq.emplace(0, src); // push the source node
        dis[src] = 0; // distance from the source to the source is 0

        while (!pq.empty()) {
            auto [oldDis, curNode] = pq.top();
            pq.pop();

            if (oldDis != dis[curNode]) continue; // not equal means that the distance of this node is updated before

            for (const auto &neighbor: adj[curNode]) { // <to, weight>
                if (dis[neighbor.first] > dis[curNode] + neighbor.second) { // if we can reach the neighbor node with a smaller distance
                    dis[neighbor.first] = dis[curNode] + neighbor.second; // update the distance
                    pq.emplace(dis[neighbor.first], neighbor.first); // push the neighbor node
                }
            }
        }
    }

    int countWays(vector<vector<pair<int, int> > > &adj, int src, int dst) {
        if(src == dst) return 1; // we found a way to reach the destination from the source

        auto & ret = dp[src];
        if(~ret) return ret; // if the state is visited before return the answer

        ret = 0; // initialize the answer with 0
        for(const auto &neighbor: adj[src]) {
            if(dis[neighbor.first] < dis[src]) {
                ret = (ret % M) + (countWays(adj, neighbor.first, dst) % M) % M; // add the ways of the neighbor node to the answer
            }
        }
        return ret % M;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int> > > adj(n + 1); // adjacency list
        dis = vector<long long> (n + 1, 1e15); // initialize the distance with oo
        memset(dp, -1, sizeof dp); // initialize the dp array with -1

        for(const auto & edge: edges) { // <from, to, weight>
            auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        dijkstra(adj, n); // run dijkstra to get the distances and the number of ways to reach each node

        return countWays(adj, 1, n); // return the number of ways to reach the destination from the source using restricted paths
    }
};
```