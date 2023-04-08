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