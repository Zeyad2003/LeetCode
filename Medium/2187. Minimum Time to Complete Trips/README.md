# [2187. Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/)

## Solution
- Apply Binary Search to find the minimum time when all trips can be completed.
## Complexity
- Time complexity: `O(nlog(n))`, Where `n` is the number of trips.
- Space complexity: `O(1)`

## Code
``` cpp
class Solution {
public:

    bool can(vector<int> &time, long long total, long long mid) {
        int n = (int) time.size();
        for(int i = 0; i < n; i++) {
            total -= (mid / time[i]); // total number of trips that can be made
            if(total <= 0) return true; // we finish at time we want
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e15, ans = -1; // Set your boundaries
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(can(time, totalTrips, mid)) // Check if we can do it in `mid` time
                ans = mid, r = mid - 1; // If we can, try to minimize the time
            else l = mid + 1; // If we can't, try to increase the time
        }
        return ans;
    }
};
```
