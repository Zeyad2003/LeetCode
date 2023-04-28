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