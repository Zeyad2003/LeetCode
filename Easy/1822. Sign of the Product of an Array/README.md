# [1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)

## Solution
- Loop through the array and count the number of negative numbers.
- Also, if you found zero, return 0.
- If the number of negative numbers is odd, return -1.
- Otherwise, return 1.

## Complexity
- Time complexity: `O(n)`, where `n` is the length of the array.

- Space complexity: `O(1)`.

## Code

```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool foundZero = false; // To check if we found zero
        int numOfNeg = 0; // To count the number of negative numbers
        for(auto & i : nums) {
            foundZero |= !i; // If we found zero, set foundZero to true
            numOfNeg += (i < 0); // If current number is negative, increment numOfNeg
        }
        if(foundZero) return 0; // If we found zero, return 0
        if(numOfNeg & 1) return -1; // If numOfNeg is odd, return -1
        return 1; // You will have a positive product
    }
};
```