# [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/)
![image](https://assets.leetcode.com/users/images/413dd346-89f2-4de5-b373-97967df2af3d_1677860068.3306696.png)
## Solution
- [Slow - Accepted]: Find the pivot point and apply binary search on both sides of the pivot point, and see if the target is in one of them.
- [Fast - Accepted]: Apply binary search on the whole array, and see if the target is in the array.
## Complexity
- Time complexity: 
    - Linear Solution: `O(n + log(n))`, where `n` is the length of the array.
    - BS Solution: `O(log(n))`, where `n` is the length of the array.

- Space complexity: `O(1)`.


## Code
- Linear Solution:
```cpp
class Solution {
public:

    // Binary Search Function that return the index of the element we are looking for or -1 if not found
    int binarySearch(vector<int> &nums, int l, int r, int target) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid; // Found the element
        if (nums[mid] > target) return binarySearch(nums, l, mid - 1, target); // Search in the left half
        return binarySearch(nums, mid + 1, r, target); // Search in the right half
    }

    int search(vector<int> &nums, int target) {
        int n = (int) nums.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] > nums[i + 1]) { // Find the pivot point
                int ans = binarySearch(nums, 0, i, target);
                if (ans != -1) // Found in the left half
                    return ans;
                return binarySearch(nums, i + 1, n - 1, target); // Check if found in the right half
            }
        }
        return binarySearch(nums, 0, n - 1, target); // If the array is not rotated
    }
};
```

- BS Solution:
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int) nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid; // found the target
            if(nums[l] <= nums[mid]) { // we are in the first sorted portion
                 if(target > nums[mid] or target < nums[l]) // target is in the right portion
                     l = mid + 1;
                 else // target is in the left portion
                     r = mid - 1;
            } else { // we are in the second sorted portion
                if(target < nums[mid] or target > nums[r]) // target is in the left portion
                    r = mid - 1;
                else // target is in the right portion
                    l = mid + 1;
            }
        }
    }
};
```