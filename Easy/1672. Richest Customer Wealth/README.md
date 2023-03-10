# [1672. Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)

## Solution
- Loop for each customer.
- sum the wealth of each customer.
- compare the wealth with the max wealth.
## Complexity
- Time Complexity: `O(nm)`, where `n` is the number of customers and `m` is the number of banks.

- Space Complexity: `O(1)`


## Code
```
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for(auto & i : accounts) { // For every customer
            int sum = accumulate(i.begin(), i.end(), 0); // Sum of his accounts
            ans = max(ans, sum); // Update the answer with the maximum sum
        }

        return ans;
    }
};
```