class Solution {
public:
    int n, m;

    bool out(vector<vector<bool> > & vis, int i, int j) {
        return i < 0 or i >= n or j < 0 or j >= m or vis[i][j];
    }

    void solve(vector<vector<int> > & mat, vector<vector<bool> > &vis, int i, int j, vector<int> & ans) {
        if(out(vis, i, j)) return;
        ans.emplace_back(mat[i][j]);
        vis[i][j] = 1;
        if((i > 0 and vis[i - 1][j] ) or !i)
            solve(mat, vis, i, j + 1, ans);
        solve(mat, vis, i + 1, j, ans);
        solve(mat, vis, i, j - 1, ans);
        solve(mat, vis, i - 1, j, ans);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<bool> > vis(n + 1, vector<bool>(m + 1, 0));
        vector<int> ans;
        solve(matrix, vis, 0, 0, ans);
        return ans;
    }
};