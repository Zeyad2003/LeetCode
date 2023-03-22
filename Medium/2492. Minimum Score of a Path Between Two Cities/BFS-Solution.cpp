class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int> > > adj(n + 1); // To store the graph
        vector<bool> vis(n + 1, 0); // To mark the visited nodes

        for(auto & edge : roads) { // Build the graph
            auto [u, v, dist] = tie(edge[0], edge[1], edge[2]);
            adj[u].emplace_back(v, dist);
            adj[v].emplace_back(u, dist);
        }

        queue<int> q; // To store the nodes that should be processed
        q.emplace(1); // Start from node 1
        int ans = 1e5; // Put the answer with high value and minimize it while processing the nodes
        while(!q.empty()) {
            int curNode = q.front(); // Get the current node
            q.pop(); // Remove it from the queue
            vis[curNode] = 1; // Mark it as visited
            for(auto & edge : adj[curNode]) { // Traverse all the edges of the current node
                auto [nextNode, dist] = tie(edge.first, edge.second); // Get the next node and the distance
                ans = min(ans, dist); // Minimize the answer
                if(!vis[nextNode]) q.emplace(nextNode); // If the next node is not visited, add it to the queue
            }
        }
        return ans; // Return the answer
    }
};