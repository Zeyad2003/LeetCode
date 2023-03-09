class Solution {
public:
    int n, m; // n = number of rows, m = number of columns
    vector<vector<bool> > vis; // To mark visited cells
    int dx[4] = {0, 0, 1, -1}; // To move in 4 directions by updating row
    int dy[4] = {1, -1, 0, 0}; // To move in 4 directions by updating column

    bool out(int i, int j) { // Check if the cell is not valid
        return i < 0 or j < 0 or i >= n or j >= m or vis[i][j];
    }

    int minCost(vector<vector<int>>& grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        vis = vector<vector<bool> >(n, vector<bool> (m, false));

        deque<tuple<int, int, int> > q; // To store the cells we explore
        q.emplace_front(0, 0, 0); // <cost, i, j>
        vis[0][0] = true; // Mark the first cell as visited

        int ans = 1e7; // To store the answer
        while(!q.empty()) {
            auto [cost, i, j] = q.front(); // Get the current cell data
            q.pop_front(); // Remove the current cell from the queue

            if(i == n - 1 and j == m - 1) { // If we reached the last cell
                ans = min(ans, cost); // Update the answer
                continue; // Continue until we explore all paths
            }

            vis[i][j] = true; // Mark the current cell as visited

            for(int idx = 0; idx < 4; idx++) { // Try all 4 directions
                int x = i + dx[idx], y = j + dy[idx]; // Get the new cell coordinates
                if(out(x, y)) continue; // If the new cell is not valid, continue

                if(idx + 1 == grid[i][j]) // If the direction is the same as the grid value
                    q.emplace_front(cost, x, y); // Add the new cell to the front of the queue with the same cost
                else // If the direction is not the same as the grid value
                    q.emplace_back(cost + 1, x, y); // Add the new cell to the back of the queue with cost + 1
            }
        }
        return ans; // Return the minimum cost
    }
};