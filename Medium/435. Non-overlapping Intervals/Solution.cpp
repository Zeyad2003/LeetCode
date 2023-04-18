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