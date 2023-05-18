# [1557. Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)

## Solution:
- The smallest set of vertices is the set of nodes that has no incoming edges.
- You should use `inDegree` array to store the number of incoming edges for each node in the graph.
- Loop through all nodes from `0` to `N - 1`, if the `inDegree` of the node is `0`, then add it to the result.
- Finally, return the result.

## Complexity
- Time Complexity: `O(N)`, where `N` is the number of nodes in the graph.

- Space Complexity: `O(N)`, for `inDegree` array.

## Code
### C++
```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int inDegree[n];
        memset(inDegree, 0, sizeof(inDegree));
        for (auto &edge : edges) inDegree[edge[1]]++;
        vector<int> ret;
        
        for (int node = 0; node < n; node++)
            if(!inDegree[node]) ret.emplace_back(node);
        
        return ret;
    }
};
```

### JavaScript
```javascript
var findSmallestSetOfVertices = function(n, edges) {
    let inDegree = new Array(n).fill(0);
    let ret = [];

    for(let [u, v] of edges)
        inDegree[v]++;

    for(let node = 0; node < n; node++)
        if(!inDegree[node])
            ret.push(node);

    return ret;
};
```

### Python
```python
class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        ret = []
        inDegree = [0] * n

        for [u, v] in edges:
            inDegree[v] += 1

        for node in range(0, n):
            if not inDegree[node]:
                ret.append(node)

        return ret
```

### Java
```java
class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> ret = new ArrayList<>();
        int[] inDegree = new int[n];

        for (List<Integer> edge : edges)
            inDegree[edge.get(1)]++;

        for(int node = 0; node < n; node++)
            if(inDegree[node] == 0) ret.add(node);

        return ret;
    }
}
```