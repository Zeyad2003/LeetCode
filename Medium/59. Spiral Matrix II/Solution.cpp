class Solution {
public:

    bool out(int i, int j, int n) {
        return i < 0 or i >= n or j < 0 or j >= n;
    }

    void dfs(vector<vector<int> > &ans, vector<vector<bool> > &vis, int n, int i = 0, int j = 0, int val = 1) {
        if(out(i, j, n) or vis[i][j]) return;
        vis[i][j] = true;
        ans[i][j] = val;

        if((i > 0 and vis[i - 1][j] ) or !i)
            dfs(ans, vis, n, i, j + 1, val + 1);
        dfs(ans, vis, n, i + 1, j, val + 1);
        dfs(ans, vis, n, i, j - 1, val + 1);
        dfs(ans, vis, n, i - 1, j, val + 1);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans = vector<vector<int> >(n, vector<int>(n, 0));
        vector<vector<bool> > vis = vector<vector<bool> >(n, vector<bool>(n, 0));
        dfs(ans, vis, n);
        return ans;
    }
};