# [389. Find the Difference](https://leetcode.com/problems/find-the-difference/)

## Solution
- Loop through first string and sum up the ASCII value of each character.
- Loop through second string and subtract the ASCII value of each character.
- The difference is the character that is not in the first string.
## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the string.

- Space Complexity: `O(1)`.
## Code
``` cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = (int) s.size();
        int m = (int) t.size();
        int sum = 0;

        for(int i = 0; i < n; i++) // Add every character to sum of s
            sum += s[i];

        for(int i = 0; i < m; i++) // Subtract every character from sum of t
            sum -= t[i];

        return (char) abs(sum); // The difference is the missing character
    }
};
```