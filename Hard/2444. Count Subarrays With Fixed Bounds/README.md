# [2444. Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)

## Solution
- For each element in the array, we need to find the number of subarrays that ends with this element and satisfies the condition.
- We can use two pointers to find the left and right bound of the subarray.
- If you find element less than minK or greater than maxK, you will start again from the next element.
## Complexity
- Time complexity: `O(n)` where n is the length of array.


- Space complexity: `O(1)`.


## Code
``` cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = (int) nums.size();
        long long ans = 0;

        int mnIdx = -1, mxIdx = -1, bound = -1;
        for (int i = 0; i < n; ++i) {
            if(nums[i] < minK or nums[i] > maxK)
                bound = i; // make any subarray invalid so start counting from the next element
            if(nums[i] == minK)
                mnIdx = i; // find the max idx for minK
            if(nums[i] == maxK)
                mxIdx = i; // find the max idx for maxK

            // if you have both minK and maxK, then it causes min(mnIdx, mxIdx) - bound subarrays
            ans += max(0, min(mnIdx, mxIdx) - bound); 
        }
        return ans;
    }
};
```