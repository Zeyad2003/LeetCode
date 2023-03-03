# [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)
![image](https://assets.leetcode.com/users/images/413dd346-89f2-4de5-b373-97967df2af3d_1677860068.3306696.png)
## Solution
- **Easy-Solution:** You can use find() function to find the required index or -1 if not found.
- **Challenge-Solution:** Implement find() function by yourself and there's 2 approaches you can use any of them:
   1. **Brute Force:** Loop over the string and for every index start to compare it with the pattern, if you find a match return the index, if not return -1.
   2. **KMP:** Use KMP algorithm to find the index of the first occurrence of the pattern and return it, if not found return -1.

## Complexity
- Time complexity:
  - **Using find() function:** Unspecified, but generally up to linear in length()-pos times the length of the sequence to match (worst case).
  - **Brute Force:** O(nm), where n is the length of the string, and m is the length of the pattern.
  - **KMP:** O(n + m), where n is the length of the string, and m is the length of the pattern.

- Space complexity: 
    - **Using find() function:** O(m), where m is the length of the pattern.
    - **Brute Force:** O(1), no extra space is used.
    - **KMP:** O(m), the length of the pattern, for the table we create.

## Videos for KMP Algorithm
- English
  - [KMP - Tushar Roy](https://youtu.be/GTJr8OvyEVQ)
  - [KMP - Abdul Bari](https://youtu.be/V5-7GzOfADQ)
- Arabic
  - [KMP - Mostafa Saad - Part1](https://youtu.be/vjxLlFTKhrU)
  - [KMP - Mostafa Saad - Part2](https://youtu.be/VBaPXRcHIk8)
## Code
- **Using find() function:**
```cpp
// Zeyad Nasef
class Solution {
public:

    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
```
- **Brute Force:**
```cpp
// Zeyad Nasef
class Solution {
public:

    int strStr(string haystack, string needle) {
        int n = (int) haystack.size(), m = (int) needle.size();

        for(int i = 0; i <= n - m; i++) { // loop over the last valid index we can start comparing from
            int j = 0;
            for(; j < m; j++) { // loop over the pattern
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == m) return i; // we found the pattern
        }

        return -1;
    }
};
```
- **KMP:**
```cpp
// Zeyad Nasef
class Solution {
public:

    // build the prefix array for the pattern
    vector<int> build(string &pat) {
        int n = (int) pat.size();
        int i = 1, j = 0;
        vector<int> v(n, 0);

        while (i < n) {
            if (pat[i] == pat[j]) v[i++] = ++j;

            else if (j > 0) j = v[j - 1];

            else i++;
        }

        return v;
    }

    int strStr(string haystack, string needle) {
        vector<int> patTable = build(needle);

        int n = (int) haystack.size(), m = (int) needle.size();

        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++, j++; // move to the next character
                if (j == m) return i - j; // we found the pattern
            }
            else if (j > 0) j = patTable[j - 1]; // go to the first index that matches the prefix of the pattern
            else i++; // move to the next character in the string
        }

        return -1;
    }
};
```