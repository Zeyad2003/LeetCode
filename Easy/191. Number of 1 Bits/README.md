# [191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

## Solution
- You can use `__builtin_popcount` to count the number of 1 bits in an integer.
- Also, you can use apply binary conversion and count the number of 1 bits.

## Complexity
- Time complexity: `O(1)`

- Space complexity: `O(1)`.


## Code
``` cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
```
