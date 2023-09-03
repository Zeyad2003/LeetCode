# [2707. Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/)

![Fast-Solution](https://github.com/Zeyad2003/LeetCode/assets/87117386/12614cc5-98ce-407b-9534-e95d45158b6a)

## Solution:
- On every index on string `s` You decide to skip it or try to take any word from all words in `dictionary` that can match any substring that starts with the current index.
- I think it's obvious that we need `Dynamic Programming` here.
- We try all different states.
    - For every index we try to skip it first and minimize the number of left characters, then we iterate on all words to see if it matches a substring that starts with the current index `i`
    - If it matches we go to `i + wordSize` and keep doing the same until we finish the string.

## Complexity
- Time Complexity: `O(N * M * K)`, where `N` is the length of `s` and `M` is the length of `Dictionary` and `K` is the length of `dictionary[i]`.

- Space Complexity: `O(N)` for the `dp` array and the recursive calls.

## Code
### C++
```cpp
class Solution {
public:

    int dp[51];
    const int MX = 100;

    int solve(string & s, vector<string> &dictionary, int i = 0) {
        if(i >= (int) s.size()) return 0;

        auto & ret = dp[i];
        if(~ret) return ret;

        ret = MX;

        ret = min(ret, solve(s, dictionary, i + 1) + 1);
        for(auto & word : dictionary) {
            int wordSize = (int) word.size();
            string sub = s.substr(i, wordSize);
            if(sub == word)
                ret = min(ret, solve(s, dictionary, i + wordSize));
        }

        return ret;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof dp);
        return solve(s, dictionary);
    }
};
```

### Java
```java
class Solution {
    public int [] dp;
    final int MX = 100;

    public int solve(String s, String[] dictionary, int i) {
        if(i >= s.length()) return 0;

        if(dp[i] != -1) return dp[i];
        int ret = MX;

        ret = Math.min(ret, solve(s, dictionary, i + 1) + 1);
        for(String word : dictionary) {
            int wordSize = word.length();
            String sub = s.substring(i, Math.min(i + wordSize, s.length()));
            if(sub.equals(word))
                ret = Math.min(ret, solve(s, dictionary, i + wordSize));
        }

        return dp[i] = ret;
    }

    public int minExtraChar(String s, String[] dictionary) {
        dp = new int[s.length() + 1];
        Arrays.fill(dp, -1);
        return solve(s, dictionary, 0);
    }
}
```

### JavaScript
```javascript
let dp;
const MX = 100;

var minExtraChar = function(s, dictionary) {
    dp = new Array(s.length);
    dp.fill(-1);
    return solve(s, dictionary, 0);
};

let solve = (s, dictionary, i) => {
    if(i >= s.length) return 0;

    let ret = dp[i];
    if(~ret) return ret;

    ret = MX;

    ret = Math.min(ret, solve(s, dictionary, i + 1) + 1);
    for(let idx = 0; idx < dictionary.length; idx++) {
        let word = dictionary[idx];
        const wordSize = word.length;
        const sub = s.substring(i, i + wordSize);
        if(sub == word)
            ret = Math.min(ret, solve(s, dictionary, i + wordSize));
    }

    return dp[i] = ret;
};
```

### Python
```python
class Solution(object):
    def __init__(self):
        self.dp = []
        self.MX = 100

    def solve(self, s, dictionary, i):
        if i >= len(s):
            return 0

        if self.dp[i] != -1:
            return self.dp[i]

        ans = self.MX

        ans = min(ans, self.solve(s, dictionary, i + 1) + 1)

        for word in dictionary:
            wordSize = len(word)
            if s[i : i + wordSize] == word:
                ans = min(ans, self.solve(s, dictionary, i + wordSize))

        self.dp[i] = ans
        return ans

    def minExtraChar(self, s, dictionary):
        self.dp = [-1] * len(s)
        return self.solve(s, dictionary, 0)

```
