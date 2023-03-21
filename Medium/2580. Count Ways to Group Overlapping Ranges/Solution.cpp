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