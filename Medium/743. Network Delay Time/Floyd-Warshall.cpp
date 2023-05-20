class Solution {
public:
    void floyd(vector<vector<int> > &adj, int n) {
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); // Relaxation Step
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > adj(n + 1, vector<int> (n + 1, 1e9));
        for(auto & i : times)
            adj[i[0]][i[1]] = i[2];

        for(int i = 1; i <= n; i++) adj[i][i] = 0; // Distance from a node to itself is 0

        floyd(adj, n + 1); // Get the shortest path from every node to every other node
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, adj[k][i]); // Get the maximum time taken to reach any node from k
        return ans == 1e9 ? -1 : ans;
    }
};