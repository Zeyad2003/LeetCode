# [1299. Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)
![fast.png](https://assets.leetcode.com/users/images/86aa5dd7-a9a4-4949-a283-c4c31ca2e1b3_1677763521.1599724.png)

## Solution
- You need to loop backwards and keep the maximum value from the right side.
- For every element from backwards, replace it with max value you saved.

## Complexity
- Time complexity: `O(n)` where n is the size of the array.


- Space complexity: `O(1)`.


## Code
``` cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // The first next greater element will be the last element in the array
        int nxtG = arr.back();
        
        int n = (int) arr.size(); // array size

        // No element to the right of the last element
        arr[n - 1] = -1;
        
        // Loop through the array backwards starting from the second last element
        for(int i = n - 2; i >= 0; i--) {
            // Save the current element to check if it will be used as the next greater element
            int tmp = arr[i];
            
            // Set the current element of the input vector to the next greater element
            arr[i] = nxtG;
            
            // Update the nxtG with the max value
            nxtG = max(nxtG, tmp);
        }
        
        return arr;
    }
};
```