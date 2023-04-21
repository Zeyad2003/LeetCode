# [879. Profitable Schemes](https://leetcode.com/problems/profitable-schemes/)

## Solution
- Use `Dynamic Programming` technique to try all possible combinations, and memoize the result.
- `dp[i][j][k]` is the number of schemes that can be chosen from the first `i` crimes, with `j` members and at least `k` profit.
- For every crime, we can either take it or leave it.
- If we take it, we need to check if we have enough members to do so.
- If we leave it, we just move on to the next crime.
- The base case is when we have no more crimes to check, and we have at least `k` profit, and we didn't use more than `n` members.
## Complexity
- Time Complexity: `O(N ^ 3)`, where `N` is the length of the group.
- Space Complexity: `O(N ^ 3)`, for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    int sz;
    const static int N = 105, M = 1e9 + 7;
    int dp[N][N][N];

    int solve(vector<int> &group, vector<int> &profit, int n, int minProfit, int i = 0) {
        if(n < 0) return 0;
        if(i >= sz) return minProfit <= 0;

        if(minProfit <= 0) minProfit = 0; // Handle out of bound
        auto & ret = dp[i][n][minProfit];
        if(~ret) return ret;

        ret = 0;

        ret = ((ret % M) + (solve(group, profit, n, minProfit, i + 1) % M)) % M; // Leave 
        ret = ((ret % M) + (solve(group, profit, n - group[i], minProfit - profit[i], i + 1) % M)) % M; // Take

        return ret;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz = (int) group.size();
        memset(dp, -1, sizeof(dp));
        return solve(group, profit, n, minProfit);
    }
};
```

### Java
```java
class Solution {
    final int M = 1000000007, N = 105;
    int [][][]dp = new int[N][N][N];
    int sz;

    int solve(int []group, int []profit, int n, int minProfit, int i) {
        if(n < 0) return 0;
        if(i >= sz) return minProfit <= 0 ? 1 : 0;

        if(minProfit < 0) minProfit = 0; // Handle out of bound
        if(dp[i][n][minProfit] != -1) return dp[i][n][minProfit];

        int ret = 0;

        ret = ((ret % M) + (solve(group, profit, n, minProfit, i + 1) % M)) % M;
        ret = ((ret % M) + (solve(group, profit, n - group[i], minProfit - profit[i], i + 1) % M)) % M;

        return dp[i][n][minProfit] = ret;
    }

    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        sz = group.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(group, profit, n, minProfit, 0);
    }
}
```

# Eid Mubarak :)