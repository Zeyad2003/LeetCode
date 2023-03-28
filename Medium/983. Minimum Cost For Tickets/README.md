# [983. Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)

## Solution
- Use `Dynamic Programming` to find the best cost from day `i` to the end.
## Complexity
- Time Complexity: `O(nlog(n))` where `n` is the max day in `days`.
- Space Complexity: `O(n)`, for the `dp` array.
## Code
```cpp
class Solution {
public:
    int dp[380]; // dp[i] -> minimum cost to travel from day i to the end
    const int oo = 1e8; // infinity

    int solve(vector<int> &days, vector<int> &costs, int day = 1) { // Get the minimum cost to travel from day to the end
        if(day > days.back()) return 0; // Finish all days

        auto & ret = dp[day];
        if(~ret) return ret; // Found before -> Return it

        ret = oo; // Initialize with infinity

        auto it = lower_bound(days.begin(), days.end(), day);
        if(it != days.end() and *it == day) { // If we are in a travel day -> try all three options and minimize
            ret = min(ret, solve(days, costs, day + 1) + costs[0]);
            ret = min(ret, solve(days, costs, day + 7) + costs[1]);
            ret = min(ret, solve(days, costs, day + 30) + costs[2]);
        } else ret = min(ret, solve(days, costs, day + 1)); // No travel -> You can skip this day

        return ret; // Return the minimum cost
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof dp); // Initialize dp with -1
        return solve(days, costs); // Return the minimum cost
    }
};
```