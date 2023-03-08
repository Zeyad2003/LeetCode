class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = (int) coordinates.size();
        sort(coordinates.begin(), coordinates.end()); // Sort the points by x

        // Get the slope = y2 - y1 / x2 - x1
        double slop = double(coordinates[1][1] - coordinates[0][1]) / double(coordinates[1][0] - coordinates[0][0]);

        // Loop over the points and check if the slope is the same
        for(int i = 2; i < n; i++) {
            double curSlop = double(coordinates[i][1] - coordinates[i - 1][1]) / double(coordinates[i][0] - coordinates[i - 1][0]);
            if(curSlop != slop) return false;
        }

        return true;
    }
};