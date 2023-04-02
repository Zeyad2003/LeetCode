# [2300. Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)

## Solution
- Sort portions vector and for every element in spells vector, find the smallest value in potions that make a successful pair.
- Then count all values greater than or equal to this value.
## Complexity
- Time Complexity: `O(n + mlog(m))` where `n` is the length of `spells` and m is the length of `potions`.
- Space Complexity: `O(n)`, for the `pairs` vector.
## Code
```cpp
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = (int) spells.size(), m = (int) potions.size(); // Get the size of the 2 vectors
        vector<int> pairs(n); // Create a vector to store the number of successful pairs for each spell
        sort(potions.begin(), potions.end()); // Sort potions vector to apply Binary-Search

        for(int i = 0; i < n; i++) { // Loop through every spell and find the number of successful pairs
            long long target = ceil((double) success / spells[i]); // Calculate the minimum value that make a successful pair
            int it = lower_bound(potions.begin(), potions.end(), target) - potions.begin(); // Find its nearest index
            pairs[i] = m - it; // All values greater than it are valid so count all of them
        }

        return pairs; // Return your answer
    }
};
```