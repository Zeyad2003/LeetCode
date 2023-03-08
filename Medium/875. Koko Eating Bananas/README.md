# [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

## Solution
- Apply binary search to find the minimum speed we can eat all bananas.

## Complexity
- Time complexity: `O(nlog(n))`, where `n` is the length of the array.

- Space complexity: `O(1)`.

## Code

```cpp
class Solution {
public:

    bool can(vector<int> &arr, int h, int mid) {
        long long cmp = 0;

        // Get the number of house needed to finish all piles
        for(const auto & it : arr) {
            double val = (double) it / (double) mid;
            cmp += (int) ceil(val);
        }

        return cmp <= h; // Compare if it is less than or equal the number of hours
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9, ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(can(piles, h, mid)) { // Check if we can use mid as the speed
                ans = mid; // Update the answer
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};
```