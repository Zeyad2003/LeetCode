class Solution {
public:

    vector<long long> dis; // Stores the distance from the source to each node
    vector<long long> cntWays; // Stores the number of ways to reach each node
    const int M = 1e9 + 7;

    void dijkstra(vector<vector<pair<int, int> > > &adj, int src) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<> > pq; // min heap to get the node with the minimum distance

        pq.emplace(0, src); // push the source node
        dis[src] = 0; // distance from the source to the source is 0
        cntWays[src] = 1; // there is only one way to reach the source from the source

        while (!pq.empty()) {
            auto [oldDis, curNode] = pq.top();
            pq.pop();

            if (oldDis > dis[curNode]) continue; // not equal means that the distance of this node is updated before

            for (const auto &neighbor: adj[curNode]) { // <to, weight>
                if (dis[neighbor.first] > dis[curNode] + neighbor.second) { // if we can reach the neighbor node with a smaller distance
                    dis[neighbor.first] = dis[curNode] + neighbor.second; // update the distance
                    pq.emplace(dis[neighbor.first], neighbor.first); // push the neighbor node
                    cntWays[neighbor.first] = cntWays[curNode]; // start counting the ways from the current node
                }
                else if(dis[neighbor.first] == dis[curNode] + neighbor.second) { // if we found new path with the same distance
                    cntWays[neighbor.first] += cntWays[curNode]; // add the ways of `from` node to the ways of `to` node
                    cntWays[neighbor.first] %= M; // take the mod
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int> > &roads) {
        vector<vector<pair<int, int> > > adj(n);
        cntWays = vector<long long>(n, 0);
        dis = vector<long long> (n, 1e16);

        for(const auto & road : roads) { // build the graph
            auto [u, v, w] = tie(road[0], road[1], road[2]);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        dijkstra(adj, 0); // run dijkstra from the source node

        return (int) cntWays[n - 1]; // return the number of ways to reach the destination node
    }
};