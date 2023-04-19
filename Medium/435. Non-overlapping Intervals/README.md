# [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

## Solution
- Sort the intervals based on the end time -> smaller end time comes first.
- Keep track of the max end time in a variable r.
- When you meet an interval that overlap with the max end time, remove it by increasing the ans variable.
- Else, update the max end time to the current interval's end time.
## Complexity
- Time Complexity: `O(nlogn)`, for sorting the intervals, and `n` is the number of intervals
- Space Complexity: `O(1)`, no extra space is used
## Code
```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        // Sort the intervals based on the end time -> smaller end time first
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if(a[1] == b[1]) return a[0] < b[0]; // End time is same, sort based on start time
            return a[1] < b[1]; // Sort based on end time
        });

        int r = intervals[0][1], ans = 0; // Keep the max end time in variable r, and ans for the intervals to be removed
        for (int i = 1; i < (int) intervals.size(); i++) {
            if (intervals[i][0] < r) ans++; // If the left less than the max end time -> there's an overlap -> Remove it
            else r = intervals[i][1]; // Update the max end time
        }

        return ans; // Return the intervals to be removed
    }
};
```