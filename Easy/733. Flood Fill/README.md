# [733. Flood Fill](https://leetcode.com/problems/ipo/)

## Solution
Just use dfs to fill the image from the starting cell, then call the function recursively on the adjacent cells.
## Complexity
- Time complexity: `O(n)` where n is the number of pixels in the image.


- Space complexity: `O(n)`.


## Code
``` cpp
class Solution {
public:
    int val, n, m; // the value of the starting cell, the number of rows and columns
    vector<vector<bool> > vis; // a 2D array to mark the visited cells
    
    // dx and dy to get the four directions
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    // to check if the cell is not valid
    bool out(int i, int j) {
        return i < 0 or i >= n or j < 0 or j >= m or vis[i][j];
    }
    
    // the dfs function to fill the image recursively
    void dfs(vector<vector<int> > & grid, int color, int i, int j) {
        grid[i][j] = color; // change the color of the current cell
        vis[i][j] = true; // mark the current cell as visited
        
        for(int idx = 0; idx < 4; idx++) { // loop over the four directions and call the function recursively
            int newI = i + dx[idx];
            int newJ = j + dy[idx];
            if(!out(newI, newJ) and grid[newI][newJ] == val) // check that the cell is valid 
                dfs(grid, color, newI, newJ);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int> > & image, int sr, int sc, int color) {
        val = image[sr][sc];
        n = (int)image.size(), m = (int)image[0].size();
        vis = vector<vector<bool> > (n + 1, vector<bool>(m + 1, false));
        dfs(image, color, sr, sc);
        return image;
    }
};
```
