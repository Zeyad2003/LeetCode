# [1502. Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)

## Solution
- Sort the array, As it will be the best order to find the best difference between the numbers.
- Loop through the array and find the difference between the current number and the previous number.
- If the difference is not equal to the first difference, return false.
- Otherwise, return true.
## Complexity
- Time complexity: `O(nlog(n))`, where `n` is the length of the array.

- Space complexity: `O(1)`.

## Code

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0]; // Get the difference between the first two elements

        for(int i = 1; i < (int) arr.size(); i++)
            if(arr[i] - arr[i - 1] != diff) // If the difference between any other two numbers not equal to the first difference
                return false; // We can't find an arithmetic progression

        return true; // We can find an arithmetic progression
    }
};
```