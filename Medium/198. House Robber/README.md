# [198. House Robber](https://leetcode.com/problems/house-robber/description/)

## Solution:

- It's a straightforward dynamic programming problem.
- Just try all the possibilities and return the maximum.
- Pick or Leave the current house.
   - If you pick the current house, you cannot pick the next one => move the index by 2.
   - If you leave the current house, you can pick the next one => move the index by 1.

## Complexity
- Time Complexity: `O(n)`, where `n` is the length of `nums`.

- Space Complexity: `O(n)` for the `dp` array and recursive calls.

## Code
### C++
```cpp
class Solution {
public:

    int rob(vector<int>& nums) {
        int sz = (int) nums.size();
        int dp[101];
        memset(dp, -1, sizeof dp);

        function<int(int)> solve = [&](int i) {
            if(i >= sz) return 0;
            if(~dp[i]) return dp[i];
            return dp[i] = max(solve(i + 1), nums[i] + solve(i + 2));
        };

        return solve(0);
    }
};
```

### Java
```java
class Solution {
    public int rob(int[] nums) {
        int sz = nums.length;
        int[] dp = new int[101];
        Arrays.fill(dp, -1);

        Function<Integer, Integer> solve = new Function<Integer, Integer>() {

            public Integer apply(Integer i) {
                if (i >= sz) return 0;
                if (dp[i] != -1) return dp[i];
                return dp[i] = Math.max(apply(i + 1), nums[i] + apply(i + 2));
            }
        };
        return solve.apply(0);
    }
}
```

### JavaScript
```javascript
var rob = function(nums) {
    let sz = nums.length;
    let dp = new Array(101).fill(-1);
    
    const solve = (i) => {
        if (i >= sz) return 0;
        if (dp[i] !== -1) return dp[i];
        return dp[i] = Math.max(solve(i + 1), nums[i] + solve(i + 2));
    };

    return solve(0);
};
```

### Python
```python
class Solution(object):
    def rob(self, nums):
        sz = len(nums)
        dp = [-1] * 101

        def solve(i):
            if i >= sz:
                return 0
            if dp[i] != -1:
                return dp[i]
            dp[i] = max(solve(i + 1), nums[i] + solve(i + 2))
            return dp[i]
        
        return solve(0)
```
