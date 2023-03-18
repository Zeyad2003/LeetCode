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