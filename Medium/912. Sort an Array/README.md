# [912. Sort an Array](https://leetcode.com/problems/sort-an-array/) 
![fast.png](https://assets.leetcode.com/users/images/a6e72eb7-c8a6-4500-b561-81c830146cba_1677654687.5122967.png)

## Some Primary Questions
- How the problem's constraints help us ?
- Based on the range of the numbers, what is the best sorting algorithm we can use ?
- How negative values affect the code implementation ?

## Approach
Based on the small range of numbers, we should use count sort which provides the best time complexity to sort elements with small values.

## Complexity
- Time complexity: **O(n)**, where n is the size of the input array.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->


- Space complexity: **O(MX)**, where MX is the maximum possible value of the input array. In this case, MX is 1e5+5.
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

## Code
``` cpp
class Solution {
public:
    const int MX = 1e5 + 5; // Max size for the range of numbers
    const int  offset = 5e4; // To handle negative vlaues

    vector<int> sortArray(vector<int>& nums) {
        // Create a counting array of size MX
        int cnt[MX];

        // Initialize all elements of cnt to 0
        memset(cnt, 0, sizeof(cnt));

        // Traverse on nums and increment the count of nums[i]
        for(auto & i : nums) 
            cnt[i + offset]++; // We shift numbers to make negative numbers in positive indices

        // Traverse on cnt and copy the elements back into nums in sorted order
        for(int i = 0, j = 0; i < MX; i++)
            while(cnt[i]--) 
                nums[j++] = i - offset; // Apply the opposite shift operation to put the right value

        return nums;
    }
};

```