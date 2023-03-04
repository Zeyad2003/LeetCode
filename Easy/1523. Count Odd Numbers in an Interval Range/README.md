# [1523. Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

## Solution
- Make sure that your all `low` and `high` are even then count the number easily
- if `low == high`, just check if `low` is odd 

## Complexity
- Time complexity: `O(1)` 

- Space complexity: `O(1)`.


## Code
``` cpp
class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0; 
        if(low == high) return (low & 1);
        if(low & 1) cnt++, low++; // If odd count it and move step forward
        if(high & 1) cnt++, high--; // If odd count it and move step backward
        cnt += (high - low) / 2; // count all odd numbers between them
        return cnt; // return final answer
    }
};
```
