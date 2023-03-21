# [2580. Count Ways to Group Overlapping Ranges](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/)

## Solution
- Merge all overlapping ranges.
- Count the number of separated ranges.
- So for every separated range, you can put it in group 1 or group 2, So the total number of ways is `2 ^ (cnt)`.

## Complexity
- **Time Complexity**: `O(nlog(n))`, where `n` is the length of `ranges` -> `O(nlog(n))` for sorting, `O(n)` for merging.
- **Space Complexity**: `O(1)`, but if we count the call stack depth it will be `O(log(n))`.

## Code
```cpp
class Solution {
public:
    int FastPower(long long a, long long b, int M = (int)(1e9 + 7)) { // Get a^b % M using recursion
        if (b == 0) return 1;
        long long x = FastPower(a, b / 2, M);
        x = ((x % M) * (x % M)) % M;
        if (b % 2) x = ((x % M) * (a % M)) % M;
        return x % M;
    }

    int countWays(vector<vector<int>>& ranges) {
        int n = (int) ranges.size(); // Get the size of ranges
        
        // Sort ranges by first smaller second greater
        sort(ranges.begin(), ranges.end(), [&](vector<int> &first, vector<int> &second) {
            if(first[0] == second[0]) return first[1] >= second[1];
            return first[0] < second[0];
        });

        int l = 0, r = 0; // 2 pointers used to merge overlapping ranges
        int cnt = 0; // Count the number of separated ranges
        while(r < n) {
            int mx = ranges[l][1]; // Get the maximum right of the current range
            while(r + 1 < n and mx >= ranges[r + 1][0]) { // While the next range is overlapping -> merge it
                mx = max(mx, ranges[r + 1][1]);
                r++; // Move the right pointer
            }
            r++; // Move to next one
            l = r; // Update the left pointer
            cnt++; // Count this separated range
        }
        return FastPower(2, cnt); // Return the number of ways % 1e9 + 7
    }
};
```