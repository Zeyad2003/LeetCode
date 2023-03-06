# [1539. Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)

## Solution
- [Slow - Accepted]: Use Brute-Force and count the missing numbers until you reach the kth missing number.
- [Fast - Accepted]: Use Binary Search and for every mid you calculate the number of missing numbers until mid, then update the left and right pointers. 

## Complexity
- Time complexity: `O(log(n) ^ 2)`

- Space complexity: `O(1)`.


## Code
``` cpp
class Solution {
public:

    // test if mid can be the answer
    bool test(vector<int> &arr, int k, int mid) {
        int n = (int) arr.size();
        auto idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin(); // find the number of elements before it
        if(idx < n and arr[idx - 1] == mid) return false; // if it in the array return false
        return mid - idx == k; // check if it is the K-th missing element
    }

    int findKthPositive(vector<int>& arr, int k) {
        int n = (int) arr.size();

        if(arr.back() - n == 0) // if no missing elements in the array
            return arr.back() + k;

        if(k < arr[0]) // if the K-th missing element is before the first element in the array
            return k;

        int l = 1, r = 2005;
        while(l < r) {
            int mid = l + (r - l) / 2;
            auto idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin(); // get the number of elements before it
            if(mid - idx == k) { // test [mid - 1, mid + 1]
                if(test(arr, k, mid - 1))
                    return mid - 1;

                if(test(arr, k, mid))
                    return mid;

                return mid + 1;
            }
            else if(mid - idx > k) // check the left portion
                r = mid;
            else // check the right portion
                l = mid;
        }
        return 0;
    }
};
```
