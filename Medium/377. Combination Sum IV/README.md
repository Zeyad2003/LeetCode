# [377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)
![Fast](https://github.com/Zeyad2003/LeetCode/assets/87117386/bab5e948-41ad-42fe-bf63-f65b2e5b70cc)

## Solution:
- The problem asks us to find the number of combinations to get the target value.
- There's a style in `Dynamic Programming` called `Counting`, that can help us to find out the solution.
- By trying all different states and count the valid ones, we can get the answer.
- Check the code for better understanding.

## Complexity
- Time Complexity: `O(N * M)`, where `N` is the maximum value of `target` and `M` is the length of `nums`.

- Space Complexity: `O(N)`, for `dp` array.

## Code
### C++
```cpp
class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        int dp[target];
        memset(dp, -1, sizeof dp);
        function<int(int)> solve = [&](int val) -> int {
            if(val > target) return 0;
            if(val == target) return 1;

            auto & ret = dp[val];
            if(~ret) return ret;

            ret = 0;
            for(auto & it : nums)
                ret += solve(val + it);
            return ret;
        };
        return solve(0);
    }
};
```

### Java
```java
import java.util.Arrays;

class Solution {
    int[] dp;

    int solve(int[] nums, int target, int val) {
        if (val > target)
            return 0;
        if (val == target)
            return 1;

        if (dp[val] != -1)
            return dp[val];

        int ret = 0;
        for (int it : nums)
            ret += solve(nums, target, val + it);
        return dp[val] = ret;
    }

    public int combinationSum4(int[] nums, int target) {
        dp = new int[target];
        Arrays.fill(dp, -1);

        return solve(nums, target, 0);
    }
}
```

### JavaScript
```javascript
let dp = [];

let solve = (nums, target, val) => {
    if (val > target)
            return 0;
        if (val == target)
            return 1;

        if (dp[val] != -1)
            return dp[val];

        let ret = 0;
        for (const it of nums)
            ret += solve(nums, target, val + it);
        return dp[val] = ret;
};

var combinationSum4 = function(nums, target) {
    dp = new Array(target).fill(-1);
    return solve(nums, target, 0);
};
```

### Python
```python
class Solution(object):
    def __init__ (self):
        self.dp = []

    def solve(self, nums, target, val):
        if val > target:
            return 0
        if val == target:
            return 1

        if self.dp[val] != -1:
            return self.dp[val]

        ret = 0
        
        for it in nums:
            ret += self.solve(nums, target, val + it)

        self.dp[val] = ret
        return ret


    def combinationSum4(self, nums, target):
        self.dp = [-1] * (target)
        return self.solve(nums, target, 0)
```
