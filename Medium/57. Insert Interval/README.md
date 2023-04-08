# [57. Insert Interval](https://leetcode.com/problems/insert-interval/)

## Solution
- Search for the suitable place to put the new interval using `upper_bound()` function, then merge the overlapping intervals.
## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the intervals.
- Space Complexity: `O(n)`, for the `ans` vector.
## Code
```cpp
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval); // Get the correct place to insert the new interval
        intervals.insert(it, newInterval); // Insert the new interval
        vector<vector<int> > ans; // Store the intervals after merging overlapping intervals
        ans.emplace_back(intervals[0]); // Push the first interval

        for (int i = 1; i < (int) intervals.size(); ++i) { // Iterate over the intervals
            // If the last interval in the ans vector overlaps with the current interval, merge them
            if(ans.back()[1] >= intervals[i][0]) ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
            // Else push the current interval to the ans vector
            else ans.emplace_back(intervals[i]);
        }
        
        return ans; // Return the ans vector
    }
};
```