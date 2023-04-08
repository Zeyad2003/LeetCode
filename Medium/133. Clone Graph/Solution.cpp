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