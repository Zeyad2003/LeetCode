# [59. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

## Solution:
- Use `DFS` to traverse the matrix.
- Use a variable initialized with value `1` to keep track with the value that should be inserted in the current cell.
- First, we keep going left until we reach our boundary.
- Our boundary is either the end of the matrix or a cell that we have already visited.
- Then, we go down, right, up, and left again.
- The if condition ensure that we go left only when its turn comes.
- Its turn comes when we the above row is traversed or the current row is the first row.

## Complexity
- Time Complexity: `O(N ^ 2)`, the size of the grid.
- Space Complexity: `O(N ^ 2)`, for the `vis` matrix.

## Code
### C++
```cpp
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
```

### Java
```java
class Solution {
    boolean out(int i, int j, int n) {
        return i < 0 || i >= n || j < 0 || j >= n;
    }

    void dfs(int[][] ans, boolean[][] vis, int n, int i, int j, int val) {
        if(out(i, j, n) || vis[i][j]) return;
        vis[i][j] = true;
        ans[i][j] = val;

        if((i > 0 && vis[i - 1][j] ) || i == 0)
            dfs(ans, vis, n, i, j + 1, val + 1);
        dfs(ans, vis, n, i + 1, j, val + 1);
        dfs(ans, vis, n, i, j - 1, val + 1);
        dfs(ans, vis, n, i - 1, j, val + 1);
    }

    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        boolean[][] vis = new boolean[n][n];
        dfs(ans, vis, n, 0, 0, 1);
        return ans;
    }
}
```