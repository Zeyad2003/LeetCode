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