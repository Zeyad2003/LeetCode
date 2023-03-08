# [1790. Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

## Solution
- Loop through two strings, and If there's more than 2 differences return false.
- If there's 2 differences but with equal characters you can swap them.
## Complexity
- Time complexity: `O(n)`, where n is the length of the string.

- Space complexity: `O(1)`.

## Code

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = (int) s1.size();
        int firstConflict = -1; // The first index where the two strings differ
        int secondConflict = -1; // The second index where the two strings differ
        int cnt = 0; // The number of differences between the two strings
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
                if(cnt == 1)  // Update the first index of the difference
                    firstConflict = i;
                if(cnt == 2) // Update the second index of the difference
                    secondConflict = i;
                if(cnt > 2) return false; // If there are more than 2 differences, return false
            }
        }

        // If 2 differences were found, check if they can be swapped
        return ((s1[firstConflict] == s2[secondConflict]) and (s2[firstConflict] == s1[secondConflict]));
    }
};
```