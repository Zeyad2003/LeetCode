# [1232. Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)

## Solution
- Get the slope of the first two points.
- Loop through the other points and check if the slope is the same.
- Sort the points by x to start iterating from left point to right point.
## Complexity
- Time complexity: `O(nlog(n))`, where n is the length of `nums2`.

- Space complexity: `O(1)`.

## Code

```cpp
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
```