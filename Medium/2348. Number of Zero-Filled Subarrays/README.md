# [2348. Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/)

## Solution
- Loop through the array and when you meet a zero count the length of zeros and then the length of this chain will cause sum(1 to length) subarrays.

## Complexity
- **Time Complexity**: `O(n)`, where `n` is the length of the array.
- **Space Complexity**: `O(1)`.

## Code
```cpp
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = (int) nums.size(); // Get the size of the array
        long long ans = 0; // The final answer
        for(int i = 0; i < n; i++) {
            if(!nums[i]) { // You meet a zero
                int r = i;
                while(r < n and !nums[r]) r++; // Find the next non-zero element
                long long cnt = r - i; // Count the number of zeros
                ans += (cnt * (cnt + 1)) >> 1; // The number of subarrays will be sum from 1 to cnt (cnt * (cnt + 1) / 2)
                i = r - 1; // Move the pointer to the last zero so that it will be skipped in the next iteration
            }
        }
        return ans; // Return the answer
    }
};
```