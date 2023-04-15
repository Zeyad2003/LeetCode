# [2218. Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/)

## Solution
- Use `Dynamic Programming` to see what is the maximum profit you can get from each pile.
- You can use `Prefix Sum` to use it when try to take `j` elements from the pile.
## Complexity
- Time Complexity: `O(nm)` where `n` is the size of the piles vector and `m` is the sum of the size of each pile.
- Space Complexity: `O(nm)`, for the `dp` array.

## Code
```cpp
class Solution {
public:
    int dp[2005][1005]; // dp[i][j] -> The maximum value of coins we can get from piles[i..n - 1] if we take j coins
    int n; // The size of the piles vector

    int solve(vector<vector<int> > &piles, int k, int i = 0) {
        if(i >= n) return 0; // No more piles

        auto & ret = dp[k][i];
        if(~ret) return ret; // Calculate before -> return it

        ret = 0; // Start with a minimum value
        
        for (int j = 0; j <= min(k, (int) piles[i].size() - 1); ++j) { // For every pile, try to take [0:min(k, piles[i].size())] coins
            int val = piles[i][0] - piles[i][j]; // The summation of the coins we take
            ret = max(ret, solve(piles, k - j, i + 1) + val); // Try to take the maximum value
        }
        
        return ret; // Return your maximum value
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = (int) piles.size(); // Initialize the size of the piles vector
        memset(dp, -1, sizeof dp); // Initialize the dp array with -1

        for(int i = 0; i < n; i++) { // Prepare the prefix sum array of the piles vector
            piles[i].emplace_back(0); // Add a 0 at the end of each pile
            for (int j = (int) piles[i].size() - 2; j >= 0; --j) // Apply the prefix sum from the end to the beginning
                piles[i][j] += piles[i][j + 1];
        }

        return solve(piles, k); // Return the optimal solution
    }
};
```