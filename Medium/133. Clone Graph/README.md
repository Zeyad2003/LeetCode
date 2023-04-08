# [133. Clone Graph](https://leetcode.com/problems/clone-graph/)

## Solution
- Use `DFS` algorithm and hashtable to clone the graph recursively and store the cloned nodes in the hashtable.
## Complexity
- Time Complexity: `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
- Space Complexity: `O(V + E)`, for `mp`.
## Code
```cpp
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        if(mp.find(node) == mp.end()) {
            mp[node] = new Node(node->val);
            for(auto &neighbor : node->neighbors)
                mp[node]->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return mp[node];
    }
};
```