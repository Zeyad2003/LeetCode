# [1491. Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

## Solution
- Sum all elements then subtract minimum and maximum elements then get the average of them.

## Complexity
- Time complexity: `O(n)` where n is the length of salary array

- Space complexity: `O(1)`.


## Code
``` cpp
class Solution {
public:
    double average(vector<int>& salary) {
        long long sum = accumulate(salary.begin(), salary.end(), 0ll); // Get the sum of all elements
        sum -= *min_element(salary.begin(), salary.end()); // Subtract minimum element 
        sum -= *max_element(salary.begin(), salary.end()); // Subtract maximum element
        return (double) (sum / (double) ((int)salary.size() - 2)); // return their average.
    }
};
```