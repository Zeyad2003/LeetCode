# [773. Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/)

## Solution
- Apply `BFS` to find the shortest path from the initial state to the target state.

## Complexity
- **Time Complexity**: `O(N!)`, where `N` is the number of cells in the board.
- **Space Complexity**: `O(N!)`, for the queue and the map.

## Code
```cpp
class Solution {
public:
    int dx[4] = {1, -1, 0, 0}; // To traverse the rows
    int dy[4] = {0, 0, 1, -1}; // To traverse the columns

    vector<vector<int> > target = {{1, 2, 3}, {4, 5, 0}}; // The target state

    bool out(int x, int y) { // Check if the current position is out of the board
        return x < 0 or x >= 2 or y < 0 or y >= 3;
    }

    pair<int, int> getZero(vector<vector<int> > &board) { // Find the position of the zero in the board
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                if(!board[i][j]) return {i, j};
        return {};
    }

    int slidingPuzzle(vector<vector<int> > &board) {
        queue<vector<vector<int> > > q; q.emplace(board); // Put the initial state in the queue
        map<vector<vector<int> >, bool> vis; // To check if the current state is visited or not
        
        for(int level = 0; !q.empty(); level++) { 
            int sz = (int)q.size();
            while(sz--) {
                auto curr = q.front(); q.pop(); // Get the current state
                if(vis[curr]) continue; // If the current state is visited, skip it
                if(curr == target) // Current state is the target then return the shortest path to reach it (level)
                    return level; 
                
                auto [r, c] = getZero(curr); // Get the position of the zero in the current state
                
                for(int i = 0; i < 4; i++) { // Traverse the rows and columns in the 4 directions
                    int nx = r + dx[i], ny = c + dy[i]; // Get the next position
                    if(!out(nx, ny)) { // If the next position is not out of the board
                        swap(curr[r][c], curr[nx][ny]); // Swap the zero with the next position
                        q.emplace(curr); // Put the new state in the queue
                        swap(curr[r][c], curr[nx][ny]); // Backtrack
                    }
                }
                vis[curr] = true; // Mark the current state as visited
            }
        }
        return -1; // If the target state is not found, return -1
    }
};
```