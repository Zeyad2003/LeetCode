# [2466. Count Ways To Build Good Strings](https://leetcode.com/problems/count-ways-to-build-good-strings/)

## Solution:
- Use `Dynamic Programming` to calculate the number of ways you can reach the land beteween `low` and `high`.
- When you inside the range try to add `zero` and add `one` and the answer should be `1 + (zero + one)` because we already have a good string.
- Else, just add `zero` and add `one` and the answer should be `(zero + one)` because we don't have a good string yet.

## Complexity
- Time Complexity: `O(high)`, the maximum value we can reach.
- Space Complexity: `O(high)`, for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    const int M = 1e9 + 7;
    vector<int> dp;
    int solve(int val, int low, int high, int zero, int one) {
        if(val > high) return 0;

        auto & ret = dp[val];
        if(~ret) return ret;

        if(val >= low) {
            return ret = 1 + ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;
        }

        return ret = ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high + 1, -1);
        return solve(0, low, high, zero, one);
    }
};
```

### Java
```java
class Solution {
    final int M = 1000000007;
    int[] dp;

    int solve(int val, int low, int high, int zero, int one) {
        if(val > high) return 0;

        if(dp[val] != -1) return dp[val];

        if(val >= low)
            return dp[val] = 1 + ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;

        return dp[val] = ((solve(val + zero, low, high, zero, one) % M) + (solve(val + one, low, high, zero, one) % M)) % M;
    }

    public int countGoodStrings(int low, int high, int zero, int one) {
        dp = new int[high + 1];
        Arrays.fill(dp, -1);
        return solve(0, low, high, zero, one);
    }
}
```