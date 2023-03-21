# [2579. Count Total Number of Colored Cells](https://leetcode.com/problems/count-total-number-of-colored-cells/)

## Solution
- **Important Observation**: For every step, if you consider the tall of the shape is `level`, then for the next step, it will increase by 2.
- for every line in the shape, the number of cells is increased by 2 except the first and last line will be increased by 3.
- So you can use dynamic programming to start form the first level where n = 1, then for every next step increase the level by 2.
- Finally, calculate the total number of cells for every step to use it again for the next step.

## Complexity
- **Time Complexity**: `O(n)`, where `n` is the input number.
- **Space Complexity**: `O(n)`, for `dp` table.

## Code
```cpp
class Solution {
public:
    long long coloredCells(int n) {
        vector<pair<long long, long long> > dp(n + 1); // <level, numberOfCells>
        dp[1] = {1, 1}; // Base Case -> level 1, 1 cell
        for(int i = 2; i <= n; i++) { // Loop until reaching level n
            auto [level, numberOfCells] = dp[i - 1]; // Get the previous level
            numberOfCells += (level << 1) + 2; // Calculate the number of new cells that will be added then add it to the next cell.
            level += 2; // Increase the level by 2
            dp[i] = {level, numberOfCells}; // Save the result
        }
        return dp[n].second; // Return the number of cells in level n
    }
};
```