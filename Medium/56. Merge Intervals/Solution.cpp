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