class Solution {
public:
    void dfs(vector<vector<int> > & graph, vector<int> & kind, vector<bool> &vis, int node, bool & bipartite) {
        vis[node] = true;

        for(auto & child : graph[node]) {
            if(!vis[child]) {
                kind[child] = 1 - kind[node];
                dfs(graph, kind, vis, child, bipartite);
            }
            else if(kind[child] == kind[node])
                bipartite = false;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        vector<int> kind(n , 0);
        vector<bool> vis(n, 0);
        bool bipartite = true;

        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs(graph, kind, vis, i, bipartite);

        return bipartite;
    }
};