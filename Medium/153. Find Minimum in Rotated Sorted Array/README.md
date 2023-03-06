# [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## Solution
- Apply binary search to find the pivot point.
- If the mid-element is greater than the right element, then the pivot point is in the right half.
- else, the pivot point is in the left half.
## Complexity
- Time complexity: `O(logn)`
- Space complexity: `O(1)`

## Code
``` cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[r]) // left is sorted so min is in right
                l = mid + 1;
            else // right is sorted so min is in left
                r = mid;
        }
        return nums[l];
    }
};
```