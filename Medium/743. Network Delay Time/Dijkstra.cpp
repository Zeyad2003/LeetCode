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