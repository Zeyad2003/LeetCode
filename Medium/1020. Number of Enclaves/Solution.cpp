class Solution {
public:
    int n, m; // The size of the grid
    int dx[4] = {0, 0, 1, -1}; // To move through the rows
    int dy[4] = {-1, 1, 0, 0}; // To move through the columns
    vector<vector<bool> > vis; // To mark the visited cells

    bool touch(int i, int j) { // Function to check if the current cell is on boarders or not
        return i == 0 or j == 0 or i == n - 1 or j == m - 1;
    }

    bool out(vector<vector<int> > &grid, int i, int j) { // Function to check if the cell is invalid
        return i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or !grid[i][j];
    }

    void dfs(vector<vector<int> >& grid, int i, int j, int &cnt, bool &f) { // DFS function that count the number of cells in the current component
        vis[i][j] = true; // Mark the current cell as visited
        cnt++; // Increase the number of cells in the current component
        if(touch(i, j)) f = false; // If the current cell is on the border then you can't walk through this component
        for(int idx = 0; idx < 4; idx++) { // Try the 4 adjacent cells
            int nx = i + dx[idx];
            int ny = j + dy[idx];
            if(!out(grid, nx, ny)) // Must be a valid cell
                dfs(grid, nx, ny, cnt, f);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0; // Variable to store the answer
        n = (int) grid.size(), m = (int) grid[0].size(); // Initialize the size of the grid
        vis = vector<vector<bool> > (n, vector<bool> (m, false)); // Mark all cells as not visited

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j] and !vis[i][j]) { // Found a new component
                    int cnt = 0; // Variable to store the number of cells in the current component
                    bool f = true; // Used to check if the current component touches the border or not
                    dfs(grid, i, j, cnt, f); // Call the DFS function to count the number of cells and check if the component is valid
                    ans += (f ? cnt : 0); // If the component is valid then add the number of cells to the answer
                }
            }
        }

        return ans; // Return the answer
    }
};