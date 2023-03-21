# [2578. Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/)

## Solution
- Convert the number to string to deal with it more easily.
- Sort the string in ascending order and loop through it.
- In each step add the current digit to one of our variables `num1`, `num2`.
- Finally, Return their sum.

## Complexity
- **Time Complexity**: `O(n)`, for looping through the string but the max size will be 9, so it is amortized constant time.
- **Space Complexity**: `O(n)`, Same as time for the string size.

## Code
```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num); // Convert the number to string to deal with it more easily
        sort(s.begin(), s.end()); // Sort the string
        string num1, num2; // The final two numbers that we should build
        bool f = false; // boolean flag to check which variable we should insert the next digit into
        for(auto & i : s) { // Iterate over the string
            if(f) num1.push_back(i); // If the flag is true, insert the digit into num1
            else num2.push_back(i); // If the flag is false, insert the digit into num2
            f = !f; // Flip the flag
        }
        return stoi(num1) + stoi(num2); // Return the sum of the two numbers
    }
};
```