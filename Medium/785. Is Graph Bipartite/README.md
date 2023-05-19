# [785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)

## Solution:
- You just need to explore the graph, and give a color or a value to every node `0` for the first set and `1` for the second set.
- Start with any color and when you move from a node to another, change to the opposite color.
- If you find a node and child with the same color, then the graph is not bipartite.

## Complexity
- Time Complexity: `O(N)`, where `N` is the number of nodes in the graph.

- Space Complexity: `O(N)`, for `kind` and `vis` arrays.

## Code
### C++
```cpp
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
```

### JavaScript
```javascript
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
```

### Python
```python
ans = True

def dfs(graph, kind, vis, node):
    global ans
    vis[node] = True

    for child in graph[node]:
        if not vis[child]:
            kind[child] = 1 - kind[node]
            dfs(graph, kind, vis, child)
        elif kind[child] == kind[node]:
            ans = False

class Solution(object):
    def isBipartite(self, graph):
        global ans
        n = len(graph)
        kind = [0] * n
        vis = [False] * n
        ans = True

        for i in range(n):
            if not vis[i]:
                dfs(graph, kind, vis, i)

        return ans
```

### Java
```java
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
```