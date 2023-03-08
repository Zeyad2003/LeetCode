class Solution {
public:

    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = (int) points.size();

        for (int i = 0; i < n; ++i) {
            if (points[i][0] == x or points[i][1] == y) { // Share a same side with x or y or both
                points[i][0] = abs(points[i][0] - x); // Distance from x
                points[i][1] = abs(points[i][1] - y); // Distance from y
            }
            else // Doesn't share any side
                points[i][0] = points[i][1] = 1e7;
        }

        int ans = -1, mn = 1e7;
        for (int i = 0; i < n; ++i) {
            if (points[i][0] + points[i][1] < mn) { // if this point share a size with x or y or both and has minimum distance from x and y
                mn = points[i][0] + points[i][1]; // update the minimum distance
                ans = i; // Update the answer with its index
            }
        }

        return ans; // Return the minimum index
    }
};