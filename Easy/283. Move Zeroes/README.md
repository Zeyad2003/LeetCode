# [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)

## Solution
- Loop through the array and when you meet zero find the next non-zero elemnt and swap them.
## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the array.

- Space Complexity: `O(1)`


## Code
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)nums.size();
        int zeroPointer = 0; // Used to track the position of the last zero you can reach from your position when you meet a zero

        for(int i = 0; i < n; i++) {
            if(!nums[i]) { // Meet a zero
                zeroPointer = max(zeroPointer, i); // Update the zero pointer to the max position it can reach
                while(!nums[zeroPointer] and zeroPointer + 1 < n) // Find the next non zero element
                    zeroPointer++;
                swap(nums[i], nums[zeroPointer]); // Swap the zero with the next non zero element
            }
        }
    }
};
```