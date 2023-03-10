# [1588. Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)

## Solution
- Loop through every element in the array
- For each element, calculate the number of odd length subarrays that it makes up
- You can get the number of arrays that start with it and end with it by using those formulas
  - `start = len(arr) - i`
  - `end = i + 1`
- Then you can get the number of arrays it makes up by multiplying those two numbers.
- Finally, to get the number of odd length arrays, you can divide that number by 2 and round up -> `(num_arrays + 1) / 2`

## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the array.

- Space Complexity: `O(1)`


## Code
```
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = (int) arr.size();
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            int start = n - i; // Number of first elements will start from i equal to n - i
            int end = i + 1; // Number of second elements will start from i equal to i + 1
            ans += (start * end + 1) / 2 * arr[i]; // (first * second + 1) / 2 is the number of subarrays that start from i and end at j
        }
        
        return ans;
    }
};
```