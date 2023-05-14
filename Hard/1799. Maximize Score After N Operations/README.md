# [1799. Maximize Score After N Operations](https://leetcode.com/problems/maximize-score-after-n-operations/)

## Solution:
- Due to small constraints, we can use `Dynamic Programming` to try all possible states and choose the best one that gives us the maximum score.
- For every operation we can try all remaining numbers that we didn't use so far, and add their score to the answer.
- We can use a `mask` to keep track of the numbers we used so far, and use it as a state in our `dp` array.

## Complexity
- Let's consider the following first:
    - `N` is the length of `nums`.
    - `M` is the number of operations `M = N / 2`.
    - the `mask` equal to `2 ^ N`.
    - the body of solve function takes `N ^ 2`.
    - the gcd function takes `O(log(A))`, where `A` is the minimum between the 2 parameters of `gcd()`.

- Time Complexity:
    - the time will be: **the multiplication of solve() parameters limits multiplied by *  the time that body takes**.
    - it will be: `O((2 ^ N) * M * (N ^ 2) * log(A)`.

- Space Complexity: `O((2 ^ N) * M)` for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    int n;

    int solve(vector<int> &arr, int mask, int i, int dp[][8]) {
        if(i > n) return 0;

        auto & ret = dp[mask][i];
        if(~ret) return ret;

        ret = 0;

        for(int bt1 = 0; bt1 < (n << 1); bt1++) {
            for(int bt2 = bt1 + 1; bt2 < (n << 1); bt2++) {
                int firstPlace = (mask & (1 << bt1)) != 0;
                int secondPlace = (mask & (1 << bt2)) != 0;
                if(firstPlace and secondPlace)
                    ret = max(ret, i * gcd(arr[bt1], arr[bt2]) + solve(arr, mask & ~(1 << bt1) & ~(1 << bt2), i + 1, dp));
            }
        }

        return ret;
    }

    int maxScore(vector<int> &nums) {
        n = (int) nums.size();
        int dp[1 << n][8];
        memset(dp, -1, sizeof dp);
        int mask = (1 << n) - 1;
        n >>= 1;
        return solve(nums, mask, 1, dp);
    }
};
```

### JavaScript
```javascript
let n, dp;

var gcd = (a, b) => {
    if(b == 0) return a;
    return gcd(b, a % b);
}

var solve = function(arr, mask, i) {
    if(i > n) return 0;

    if(dp[mask][i] != -1) return dp[mask][i];

    let ret = 0;

    for(let bt1 = 0; bt1 < (n << 1); bt1++) {
        for(let bt2 = bt1 + 1; bt2 < (n << 1); bt2++) {
            let firstPlace = (mask & (1 << bt1));
            let secondPlace = (mask & (1 << bt2));
            if(firstPlace != 0 && secondPlace != 0)
                ret = Math.max(ret, i * gcd(arr[bt1], arr[bt2]) + solve(arr, mask & ~(1 << bt1) & ~(1 << bt2), i + 1));
        }
    }

    return dp[mask][i] = ret;
}

var maxScore = function(nums) {
    n = nums.length;
    dp = Array.from({ length: 1 << n }, () => Array(8).fill(-1));

    let mask = (1 << n) - 1;
    n >>= 1;
    return solve(nums, mask, 1);
};
```

### Java
```java
class Solution {
    public int n;
    public int [][] dp;

    public int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    int solve(int[] arr, int mask, int i) {
        if(i > n) return 0;

        if(dp[mask][i] != -1) return dp[mask][i];

        int ret = 0;

        for(int bt1 = 0; bt1 < (n << 1); bt1++) {
            for(int bt2 = bt1 + 1; bt2 < (n << 1); bt2++) {
                int firstPlace = (mask & (1 << bt1));
                int secondPlace = (mask & (1 << bt2));
                if(firstPlace != 0 && secondPlace != 0)
                    ret = Math.max(ret, i * gcd(arr[bt1], arr[bt2]) + solve(arr, mask & ~(1 << bt1) & ~(1 << bt2), i + 1));
            }
        }

        return dp[mask][i] = ret;
    }

    public int maxScore(int[] nums) {
        n = nums.length;
        dp = new int[1 << n][8];
        for(int[] i : dp) Arrays.fill(i, -1);
        int mask = (1 << n) - 1;
        n >>= 1;
        return solve(nums, mask, 1);
    }
}
```