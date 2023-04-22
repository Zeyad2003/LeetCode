# [1312. Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

## Solution
- Use `Dynamic Programming` technique to try all possible ways to make the string palindrome.
- The `dp` array is a 2D array, where `dp[l][r]` is the minimum number of insertions needed to make the substring `s[l..r]` a palindrome.
- If `s[l] == s[r]`, then you can move the 2 pointers to the inside and calculate the minimum number of insertions needed for the substring `s[l + 1..r - 1]`.
- If `s[l] != s[r]`, then try the 2 options to move `l` to the right or `r` to the left.
- For all the combinations return the minimum number needed to convert the string to a palindrome one.
## Complexity
- Time Complexity: `O(N ^ 2)`, where `N` is the length of the string.
- Space Complexity: `O(N ^ 2)`, for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    int dp[505][505];

    int solve(string &s, int l, int r) {
        if(l >= r) return 0;

        auto & ret = dp[l][r];
        if(~ret) return ret;

        if(s[l] == s[r]) ret = solve(s, l + 1, r - 1);
        else ret = 1 + min(solve(s, l + 1, r), solve(s, l, r - 1));
        return ret;
    }

    int minInsertions(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, (int) s.size() - 1);
    }
};
```

### Java
```java
class Solution {
    int [][] dp = new int[505][505];

    int solve(String s, int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s.charAt(l) == s.charAt(r)) return dp[l][r] = solve(s, l + 1, r - 1);
        return dp[l][r] = 1 + Math.min(solve(s, l + 1, r), solve(s, l, r - 1));
    }

    public int minInsertions(String s) {
        for (int i = 0; i < 505; i++) {
            for (int j = 0; j < 505; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(s, 0, s.length() - 1);
    }
}
```
