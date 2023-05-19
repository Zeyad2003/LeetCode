let ans = true;
var dfs = (graph, kind, vis, node) => {
    vis[node] = true;

    for(let child of graph[node]) {
        if(!vis[child]) {
            kind[child] = 1 - kind[node];
            dfs(graph, kind, vis, child);
        } else if(kind[child] === kind[node]) ans = false;
    }
}

var isBipartite = function(graph) {
    let n = graph.length;

    let kind = new Array(n).fill(0);
    let vis = new Array(n).fill(false);
    ans = true;

    for(let i = 0; i < n; i++)
        if(!vis[i])
            dfs(graph, kind, vis, i);

    return ans;
};