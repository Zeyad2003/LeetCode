class Solution {
    public boolean bipartite;
    public void dfs(int[][] graph, int[] kind, boolean[] vis, int node) {
        vis[node] = true;

        for(int child : graph[node]) {
            if(!vis[child]) {
                kind[child] = 1 - kind[node];
                dfs(graph, kind, vis, child);
            }
            else if(kind[child] == kind[node])
                bipartite = false;
        }
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] kind = new int[n];
        boolean[] vis = new boolean[n];

        Arrays.fill(kind, 0);
        Arrays.fill(vis, false);

        bipartite = true;

        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs(graph, kind, vis, i);

        return bipartite;
    }
}