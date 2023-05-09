# [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

## Solution:
- Use `DFS` to traverse the matrix.
- First, we keep going left until we reach our boundary.
- Our boundary is either the end of the matrix or a cell that we have already visited.
- Then, we go down, right, up, and left again.
- The if condition ensure that we go left only when its turn comes.
- Its turn comes when we the above row is traversed or the current row is the first row.

## Complexity
- Time Complexity: `O(N * M)`, where `N` is the number of rows and `M` is the number of columns.
- Space Complexity: `O(N * M)`, for the `vis` matrix.

## Code
### C++
```cpp
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
```

### Java
```java
class Solution {
    public int n, m;

    boolean out(int i, int j) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    public void solve(int[][] matrix, boolean[][] vis, int i, int j, List<Integer> ans) {
        if(out(i, j) || vis[i][j]) return;
        vis[i][j] = true;
        ans.add(matrix[i][j]);

        if((i > 0 && vis[i - 1][j]) || i == 0)
            solve(matrix, vis, i, j + 1, ans);
        solve(matrix, vis, i + 1, j, ans);
        solve(matrix, vis, i, j - 1, ans);
        solve(matrix, vis, i - 1, j, ans);
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        n = matrix.length;
        m = matrix[0].length;
        boolean[][] vis = new boolean[n][m];
        solve(matrix, vis, 0, 0, ans);
        return ans;
    }
}
```