# [839. Similar String Groups](https://leetcode.com/problems/similar-string-groups/)

## Hints:
1. Imagine that we have a graph with multiple components, where each component is a group of similar strings.
2. Then the problem will be reduced to finding the number of components in the graph.
3. So to do that, you need to represent the similar strings together in a graph.

## Solution:
- Loop over the strings in the array and for each one of them, see which strings are similar to it.
- You should have adjacency list to represent the graph and put undirected edge between each pair of similar strings.
    - To find if 2 strings are similar see if there's equal or have only 2 positions `begin`, `last` that are different, then check that the 2 positions are equal `first[begin] == second[end]` and the opposite.
- Once you finish building the graph just the problem will be normal graph problem which is finding the number of connected components in the graph.
- To do that you can use `DFS` or `BFS` to traverse the graph and count the number of components.
## Complexity
- Time Complexity: `O((N ^ 2) * len)`, where `N` is the length of `strs` array, and `len` is the length of `strs[i]`.
    - `N ^ 2` for the nested loop to build the graph.
    - `len` To check if 2 strings are similar.
- Space Complexity: `O(N + M)`, for `adj` that used to build the graph, and `M` is the number of similar strings pairs.

## Code
### C++
```cpp
class Solution {
public:

    bool equal(string &first, string &second) {
        int begin = -1, end = -1;
        for(int i = 0; i < (int) first.size(); i++) {
            if(first[i] != second[i]) {
                if(~begin) {
                    if(~end) return false;
                    end = i;
                } else {
                    begin = i;
                }
            }
        }
        if(begin == -1) return true;
        if(end == -1) return false;
        return (first[begin] == second[end] and first[end] == second[begin]);
    }

    void dfs(unordered_map<string, vector<string>> &adj, unordered_map<string, bool> &vis, string &node) {
        vis[node] = true;
        for(auto & i : adj[node])
            if(!vis[i]) dfs(adj, vis, i);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = (int) strs.size();

        unordered_map<string, vector<string> > adj;
        unordered_map<string, bool> vis;

        for (int i = 0; i < n; ++i) {
            if(adj.find(strs[i]) == adj.end()) adj[strs[i]] = {};
            for (int j = i + 1; j < n; ++j) {
                if(equal(strs[i], strs[j])) {
                    adj[strs[i]].emplace_back(strs[j]);
                    adj[strs[j]].emplace_back(strs[i]);
                }
            }
        }

        int ans = 0;
        for(auto & i : adj) {
            if(!vis[i.first]) {
                ans++;
                string tmp = i.first;
                dfs(adj, vis, tmp);
            }
        }

        return ans;
    }
};
```

### Java
```java
import java.util.*;
class Solution {
    boolean equal(String first, String second) {
        int n = first.length();
        int begin = -1, end = -1;

        for (int i = 0; i < n; i++) {
            if(first.charAt(i) != second.charAt(i)) {
                if(begin != -1) {
                    if(end != -1) return false;
                    end = i;
                } else {
                    begin = i;
                }
            }
        }
        if(begin == -1) return true;
        if(end == -1) return false;
        return (first.charAt(begin) == second.charAt(end) && first.charAt(end) == second.charAt(begin));
    }

    void dfs(HashMap<String, Vector<String> > adj, HashMap<String, Boolean> vis, String node) {
        vis.put(node, true);
        for(String i : adj.get(node)) {
            if(!vis.containsKey(i)) {
                dfs(adj, vis, i);
            }
        }
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        HashMap<String, Vector<String> > adj = new HashMap<>();
        HashMap<String, Boolean> vis = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            if(!adj.containsKey(strs[i])) adj.put(strs[i], new Vector<>());
            for (int j = i + 1; j < n; ++j) {
                if(!adj.containsKey(strs[j])) adj.put(strs[j], new Vector<>());
                if(equal(strs[i], strs[j])) {
                    adj.get(strs[i]).add(strs[j]);
                    adj.get(strs[j]).add(strs[i]);
                }
            }
        }

        int ans = 0;
        for(String i : adj.keySet()) {
            if(!vis.containsKey(i)) {
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
}
```
