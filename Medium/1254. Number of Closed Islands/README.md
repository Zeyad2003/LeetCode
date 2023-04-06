# [1254. Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)

## Solution
- **Important Intuition**: If the island is closed, it means that it doesn't touch the border of the grid.
- Use `DFS` Algorithm to explore the graph.
- When you found a cell with zero value, start to `dfs` on it and check if it closed or not.
## Complexity
- Time Complexity: `O(nm)`, where `n` is the number of rows and `m` is the number of columns.
- Space Complexity: `O(nm)`, for the visited array.
## Code
```cpp
class Solution {
public:
    int n, m; // The size of the grid
    vector<vector<bool> > vis; // Used to mark the visited cells
    int dx[4] = {0, 0, 1, -1}; // Used to move on rows
    int dy[4] = {1, -1, 0, 0}; // Used to move on columns

    bool touch(int i, int j) { // Check if the cell is on the border
        return i == 0 or i == n - 1 or j == 0 or j == m - 1;
    }

    bool out(vector<vector<int> > &grid, int i, int j) { // Check if the cell is invalid
        return i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or grid[i][j];
    }

    void dfs(vector<vector<int> > &grid, int i, int j, bool &f) {
        if (out(grid, i, j)) return; // If the cell is invalid, return
        if (touch(i, j)) f = false; // Touch the boarder -> can't be closed

        vis[i][j] = true; // Mark the cell as visited

        for(int idx = 0; idx < 4; idx++) { // DFS on the 4 directions
            int nx = i + dx[idx], ny = j + dy[idx];
            dfs(grid, nx, ny, f);
        }
    }

    int closedIsland(vector<vector<int> > &grid) {
        int ans = 0; // The answer variable
        n = (int) grid.size(), m = (int) grid[0].size(); // Initialize the size of the grid
        vis = vector<vector<bool> >(n, vector<bool>(m, false)); // Initialize the visited array with false

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!out(grid, i, j)) { // If the cell is valid
                    bool f = true; // The flag to check if the island is closed
                    dfs(grid, i, j, f); // DFS on the island
                    ans += f; // If the island is closed, increment the answer
                }
            }
        }
        return ans; // Return the answer
    }
};
```