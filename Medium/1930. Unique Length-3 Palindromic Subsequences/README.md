# [1930. Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)

## Solution:
- We need to find the unique palindrome subsequence of length 3.
- So, the first observation, the first character must be the same as the last character.
- So just looping for every distinct character and find the first and last occurence of that character in `s` with counting the distinct character in between will give us the answer.

## Complexity
- Time Complexity: `O(N)`, where `N` is the length of `s`, and `find_last_of` will be performed at most 26 times.

- Space Complexity: `O(1)` the `st`, and `cntDistinct` will hold maximum 26 characters only.

## Code
### C++
```cpp
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;
        int n = (int) s.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            if(st.find(s[i]) == st.end()) {
                st.emplace(s[i]);
                int lastIdx = (int) s.find_last_of(s[i]);
                if(lastIdx != i) {
                    unordered_set<char> cntDistinct(s.begin() + i + 1, s.begin() + lastIdx);
                    ans += (int) cntDistinct.size();
                }
            }
        }

        return ans;
    }
};
```

### Java
```java
class Solution {
    public int countPalindromicSubsequence(String s) {
        Set<Character> st = new HashSet<>();
        int n = s.length(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            if(!st.contains(s.charAt(i))) {
                st.add(s.charAt(i));
                int lastIdx = s.lastIndexOf(s.charAt(i));
                if (lastIdx != i) {
                    Set<Character> cntDistinct = new HashSet<>();
                    for (int j = i + 1; j < lastIdx; j++) cntDistinct.add(s.charAt(j));
                    ans += cntDistinct.size();
                }
            }
        }
        
        return ans;
    }
}
```

### JavaScript
```javascript
var countPalindromicSubsequence = function(s) {
  let st = new Set();
  let n = s.length, ans = 0;

  for(let i = 0; i < n; i++) {
      if(!st.has(s[i])) {
          st.add(s[i]);
          let lastIdx = s.lastIndexOf(s[i]);
          if(lastIdx != i) {
              let cntDistinct = new Set(s.slice(i + 1, lastIdx));
              ans += cntDistinct.size;
          }
      }
  }

  return ans;
};
```

### Python
```python
class Solution(object):
    def countPalindromicSubsequence(self, s):
        st = set()
        ans = 0

        for i in range(len(s)):
            if s[i] not in st:
                st.add(s[i])
                lastIdx = s.rfind(s[i])
                if lastIdx != i:
                    cntDistinct = set(s[i + 1:lastIdx])
                    ans += len(cntDistinct)

        return ans
```