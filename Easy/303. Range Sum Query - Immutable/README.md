# [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

## Solution
- Use a vector to store the prefix sum of the input array and use the vector to calculate the sum of every range.
## Complexity
- Time Complexity: `O(n + q)`, where `n` is the length of the input array and `q` is the number of queries.

- Space Complexity: `O(n)`, for the `pre` array.
## Code
```cpp
class NumArray {
public:
    vector<int> pre; // prefix sum array
    NumArray(vector<int>& nums) { // Prepare prefix sum array
        pre.emplace_back(nums[0]);
        for(int i = 1; i < (int) nums.size(); i++)
            pre.emplace_back(nums[i] + pre.back());
    }

    int sumRange(int left, int right) {
        if(!left) return pre[right]; // if left is 0, pre[right] is the answer
        return pre[right] - pre[left - 1]; // else, get the prefix sum of the range
    }
};
```