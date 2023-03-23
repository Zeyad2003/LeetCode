# [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)

## Solution
- Sort the intervals by start time and add the first one to your answer vector, then loop through others and merge them one by one, if possible.
- If not possible to merge, add the current interval to the answer vector.

## Complexity
- **Time Complexity**: `O(nlog(n))`, where `n` is the length of the array.
- **Space Complexity**: `O(n)`, for `ans` array.

## Code
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = (int) intervals.size(); // Get the size of the 
        vector<vector<int> > ans; // Create a vector to store the answer 
        sort(intervals.begin(), intervals.end()); // Sort the intervals
        ans.emplace_back(intervals[0]); // Add the first interval to the answer
        for (int i = 1; i < n; ++i) { // Loop through the intervals from 1 to n
            if(ans.back()[1] >= intervals[i][0]) ans.back()[1] = max(ans.back()[1], intervals[i][1]); // Merge
            else ans.emplace_back(intervals[i]); // Add new one
        }
        return ans; // Return the answer
    }
};
```