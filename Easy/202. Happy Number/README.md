# [202. Happy Number](https://leetcode.com/problems/happy-number/)

## Solution
- Loop through the number and calculate the sum of the square of each digit
## Complexity
- Time complexity: `O(k * log(n))`, where k is the number of times the while loop runs until it returns either true or false

- Space complexity: `O(log(n))`, the size of the hashtable.

## Code

```cpp
class Solution {
public:

    int getSquareSum(int n) { // Get the sum of every (digit ^ 2)
        int sum = 0;
        while(n) {
            int x = n % 10; // Get the last digit
            sum += x * x; // Add its square to the sum
            n /= 10; // Remove the last digit
        }
        return sum; // Return the sum
    }

    bool isHappy(int n) {
        unordered_map<int, bool> store;
        while(true) {
            if(n == 1) return true; // If we reached 1, then we are happy
            if(store[n]) return false; // If we found the number before, it's a cycle
            store[n] = true; // Mark the number as visited
            n = getSquareSum(n); // Update n with the sum of its digits squared
        }
        return false; // Just to compile without errors
    }
};
```