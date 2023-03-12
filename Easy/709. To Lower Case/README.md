# [709. To Lower Case](https://leetcode.com/problems/to-lower-case/)

## Solution
- Use `tolower()` function to convert the string to lowercase.
## Complexity
- Time Complexity: `O(n)` where `n` is the length of the string.

- Space Complexity: `O(1)`.
## Code
``` cpp
class Solution {
public:
    string toLowerCase(string s) {
        for(auto & i : s)
            i = (char) tolower(i); // Use tolower() function
        return s;
    }
};
```