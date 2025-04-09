# [3375. Minimum Operations to Make Array Values Equal to K](https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/)

## Solution:

- First lets define when we have no answer:
  - There's no way to increase the values in the array, only decrease them.
  - So, if `k` is greater than the **minimum** value in the array, then it's impossible to make all values equal to `k`.

- Now, if we checked the allowed options we have, we can see that:
  - We can only decrease each unique value in the array to the value we choose.
  - So, the optimal method would be changing the greatest value to the next greater one, and keep so until reaching `k`.
  - You will find that the number of operations needed to make all values equal to `k` is equal to the **number of distinct values in the array (including `k`)** minus one (because we don't need to change `k`).

## Complexity
- Time Complexity: `O(n)`, where `n` is the length of `nums`.

- Space Complexity: `O(m)` where `m` is the number of distinct numbers in `nums` and `k`.

## Code
### C++
```cpp
class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        unordered_set<int> distinctNums;
        distinctNums.emplace(k);

        int minNum = nums[0];

        for (int i = 0; i < (int) nums.size(); i++) {
            minNum = min(minNum, nums[i]);
            distinctNums.emplace(nums[i]);
        }

        if (k > minNum) return -1;
        return (int)distinctNums.size() - 1;
    }
};

```

### Java
```java
class Solution {
    public int minOperations(int[] nums, int k) {
        HashSet<Integer> distinctNums = new HashSet<>();
        distinctNums.add(k);

        Integer minNum = nums[0];

        for (int i = 0; i < nums.length; i++) {
            minNum = Math.min(minNum, nums[i]);
            distinctNums.add(nums[i]);
        }

        if (k > minNum) return -1;
        return distinctNums.size() - 1;
    }
}

```

### JavaScript
```javascript
var minOperations = function(nums, k) {
    let distinctNums = new Set();
    distinctNums.add(k);

    let minNum = nums[0];

    for(let i = 0; i < nums.length; i++) {
        minNum = Math.min(minNum, nums[i]);
        distinctNums.add(nums[i]);
    }

    if(k > minNum) return -1;
    return distinctNums.size - 1;
};

```

### Python
```python
class Solution(object):
    def minOperations(self, nums, k):
        distinctNums = set()
        distinctNums.add(k)

        minNum = nums[0]

        for i in range(len(nums)):
            minNum = min(minNum, nums[i])
            distinctNums.add(nums[i])

        if k > minNum:
            return -1
        
        return len(distinctNums) - 1

```
