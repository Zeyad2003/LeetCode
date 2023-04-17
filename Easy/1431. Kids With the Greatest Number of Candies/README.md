# [1431. Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)

## Solution
- Find the max answer and for every element in the array try to add the extra candies and check if it is greater than or equal to the max answer.
- If it is greater than or equal to the max answer, then push true, else push false.
## Complexity
- Time Complexity: `O(n)`, where `n` is the size of the array.
- Space Complexity: `O(1)`, without counting any input or output arrays, else `O(n)`, where `n` is the size of the array.

## Code
```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end()); // Find the max element in the array
        vector<bool> ans; // Used to store the answer
        
        for (auto & i : candies) { // Loop over the candies array
            if (i + extraCandies >= mx) ans.emplace_back(true); // If the current kid can have the max number of candies, then push true
            else ans.emplace_back(false); // Else push false
        }
        
        return ans; // Return the answer
    }
};
```