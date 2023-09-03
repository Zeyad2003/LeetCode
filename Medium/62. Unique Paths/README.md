# [62. Unique Paths](https://leetcode.com/problems/unique-paths/)

![Fast-Solution](https://github.com/Zeyad2003/LeetCode/assets/87117386/c92118ff-6f39-4681-844b-49bf318b33cd)

## Solution:
- Go ahead, it's a pure `Dynamic Programming` problem.
- Just try all different ways to reach the end of the grid.
- Every time you reach the target cell, increment the answer by one.

## Complexity
- Time Complexity: `O(N * M)`, where `N` is the number of rows and `M` is the number of columns of the grid.

- Space Complexity: `O(N * M)` for the `dp` array and the recursive calls.

## Code
### C++
```cpp
class Solution {
private:
    int dp[105][105];
public:
    Solution() { memset(dp, -1, sizeof dp); }
    bool out(int m, int n, int i, int j) { return i < 0 or j < 0 or i >= m or j >= n; }
    int solve(int m, int n, int i = 0, int j = 0) {
        if(i == m - 1 and j == n - 1) return 1;

        auto & ret = dp[i][j];
        if(~ret) return ret;

        ret = 0;
        if(!out(m, n, i + 1, j)) ret += solve(m, n, i + 1, j);
        if(!out(m, n, i, j + 1)) ret += solve(m, n, i, j + 1);
        return ret;
    }
    int uniquePaths(int m, int n) {
        return solve(m, n);
    }
};
```

### Java
```java
class Solution {

    public int[][] dp;

    public boolean out(int m, int n, int i, int j) {
        return i < 0 || j < 0 || i >= m || j >= n;
    }

    public int solve(int m, int n, int i, int j) {
        if (i == m - 1 && j == n - 1)
            return 1;

        int ret = dp[i][j];
        if (ret != -1)
            return ret;

        ret = 0;
        if (!out(m, n, i + 1, j))
            ret += solve(m, n, i + 1, j);
        if (!out(m, n, i, j + 1))
            ret += solve(m, n, i, j + 1);
        return dp[i][j] = ret;
    }

    public int uniquePaths(int m, int n) {
        dp = new int[m][n];
        Arrays.stream(dp).forEach(arr -> Arrays.fill(arr, -1));
        return solve(m, n, 0, 0);
    }
}
```

### JavaScript
```javascript
let dp;
var uniquePaths = function (m, n) {
  dp = Array.from({ length: m }, () => Array(n).fill(-1));
  return solve(m, n, 0, 0);
};

let out = (m, n, i, j) => {
  return i < 0 || j < 0 || i >= m || j >= n;
};

let solve = (m, n, i, j) => {
  if (i == m - 1 && j == n - 1) return 1;

  let ret = dp[i][j];
  if (ret != -1) return ret;

  ret = 0;
  if (!out(m, n, i + 1, j)) ret += solve(m, n, i + 1, j);
  if (!out(m, n, i, j + 1)) ret += solve(m, n, i, j + 1);
  return (dp[i][j] = ret);
};
```

### Python
```python
class Solution(object):
    def __init__(self):
        self.dp = []
    
    def out(self, m, n, i, j):
        return i < 0 or j < 0 or i >= m or j >= n; 

    def solve(self, m, n, i, j):
        if i == m - 1 and j == n - 1:
            return 1

        ret = self.dp[i][j]

        if ret != -1:
            return ret

        ret = 0
        if not self.out(m, n, i + 1, j):
            ret += self.solve(m, n, i + 1, j)
        if not self.out(m, n, i, j + 1):
            ret += self.solve(m, n, i, j + 1)

        self.dp[i][j] = ret
        return ret
    
    
    def uniquePaths(self, m, n):
        self.dp = [[-1 for col in range(n)] for row in range(m)]
        return self.solve(m, n, 0, 0)
```