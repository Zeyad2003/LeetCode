# [1035. Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/)

## Solution:
- Use `Dynamic Programming` to calculate the max number of uncrossed lines.
- When you find a match this is the only time you can add 1 to the answer.
- Otherwise, you can either skip the current element in `nums1` or `nums2` and take the maximum of the two.

## Complexity
- Time Complexity: `O(N * M)`, where `N` is the length of `nums1` and `M` is the length of `nums2`.
- Space Complexity: `O(N * M)`, for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    int dp[501][501];
    int n, m;

    int solve(vector<int> &first, vector<int> &second, int i = 0, int j = 0) {
        if(i >= n or j >= m) return 0;

        auto & ret = dp[i][j];
        if(~ret) return ret;

        ret = solve(first, second, i + 1, j);
        ret = max(ret, solve(first, second, i, j + 1));
        if(first[i] == second[j])
            ret = max(ret, 1 + solve(first, second, i + 1, j + 1));

        return ret;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = (int) nums1.size(), m = (int) nums2.size();
        memset(dp, -1, sizeof dp);
        return solve(nums1, nums2);
    }
};
```

### Java
```java
class Solution {
    public int n, m;
    int dp[][] = new int[501][501];

    int solve(int[] first, int[] second, int i, int j) {
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ret = solve(first, second, i + 1, j);
        ret = Math.max(ret, solve(first, second, i, j + 1));
        if(first[i] == second[j])
            ret = Math.max(ret, 1 + solve(first, second, i + 1, j + 1));

        return dp[i][j] = ret;
    }

    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        n = nums1.length; m = nums2.length;

        for (int[] i : dp) Arrays.fill(i, -1);

        return solve(nums1, nums2, 0, 0);
    }
}
```