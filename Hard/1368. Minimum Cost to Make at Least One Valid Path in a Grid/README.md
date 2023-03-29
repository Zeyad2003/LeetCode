# [1368. Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

## Solution
- **Important Observation**: for every cell you have only 4 directions to go to, so we can see a shortest path problem to reach the target with minimum cost you can.
- Use `BFS` Algorithm to find the shortest path with minimum cost you can.
- If you are going to follow the existing direction, you don't need to pay any cost.
- If you are going to change the direction, you need to pay `1` cost.
## Complexity
- Time Complexity: `O(nm)` where `n` is the number of rows and `m` is the number of columns.
- Space Complexity: `O(nm)`, for the `vis` array.
## Code
```cpp
class Solution {
public:
    int n, m; // The size of the grid
    vector<vector<bool> > vis; // Used to mark the visited cells
    int dx[5] = {-1, 0, 0, 1, -1}; // 1-based Directional Arrays for rows
    int dy[5] = {-1, 1, -1, 0, 0}; // 1-based Directional Arrays for columns
    
    bool out(int i, int j) { // Check if the cell is invalid
        return i < 0 or j < 0 or i >= n or j >= m or vis[i][j];
    }

    int minCost(vector<vector<int>>& grid) {
        n = (int) grid.size(), m = (int) grid[0].size(); // Get the size 
        vis = vector<vector<bool> >(n, vector<bool> (m, false)); // Initialize the visited array

        deque<tuple<int, int, int> > q; // Store every state in the form of (cost, i, j)
        q.emplace_front(0, 0, 0); // cost, i, j // Push the first cell
        vis[0][0] = true; // Mark the first cell as visited

        int ans = 1e7; // Initialize the answer with a large value and minimize it
        while(!q.empty()) {
            auto [cost, i, j] = q.front(); // Get the current state
            q.pop_front(); // Pop the current state

            if(i == n - 1 and j == m - 1) { // Reach the destination
                ans = min(ans, cost); // Minimize the answer
                continue; // Continue to find if there's a better answer
            }

            vis[i][j] = true; // Mark the current cell as visited

            for(int idx = 1; idx <= 4; idx++) { // Try all the possible directions
                int x = i + dx[idx], y = j + dy[idx]; // The Updated cell
                if(out(x, y)) continue; // Invalid -> Skip

                if(idx == grid[i][j]) // You will use the existing direction -> no cost needed
                    q.emplace_front(cost, x, y); // Just push the new state
                else // Need to modify the direction -> cost needed
                    q.emplace_back(cost + 1, x, y); // Push the new state with cost + 1
            }
        }
        return ans; // Return the minimum answer
    }
};
```