# [1964. Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)

## Solution:
- If you focus on the problem requirements you will find that for every index `i` you should find an increasing subsequence from `0` to `i`.
- Bro, that's a pure LIS problem!!
- The only difference that you should involve the `i-th` element in the sequence, and the elements should be greater than **or equal** its previous elements.
- Considering the large constraints, you can use `Greedy + Binary-Search` approach to calculate the required solution.
- Just modify the if condition to add element if it's greater than or equal to the last element in the `dp` array.
- Also modify the binary search to return the index of the first element that is greater than or equal to the target element.

**Note:** in Java I implemented upper bound function by myself, as I don't know if there is a built-in function for that in java :)

## Complexity
- Time Complexity: `O(Nlog(N))`, where `N` is the length of `obstacles`.
- Space Complexity: `O(N)`, for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = (int) obstacles.size();
        vector<int> dp, ret(n);

        for(int i = 0; i < n; i++){
            if(dp.empty() or dp.back() <= obstacles[i]) {
                dp.emplace_back(obstacles[i]);
                ret[i] = (int)dp.size();
            } else {
                auto it = upper_bound(dp.begin(), dp.end(), obstacles[i]);
                *it = obstacles[i];
                ret[i] = it - dp.begin() + 1;
            }
        }

        return ret;
    }
};
```

### Java
```java
class Solution {
    public static int upperBound(int[] arr, int left, int right, int key) {
        int mid, result = -1;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (arr[mid] <= key) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid - 1;
            }
        }

        return result;
    }
    
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n = obstacles.length;
        int[] dp = new int[n];
        int[] ret = new int[n];

        int len = 0;
        for(int i = 0; i < n; i++){
            if(len == 0 || dp[len - 1] <= obstacles[i]){
                dp[len++] = obstacles[i];
                ret[i] = len;
            } else {
                int idx = upperBound(dp, 0, len - 1, obstacles[i]);
                dp[idx] = obstacles[i];
                ret[i] = idx + 1;
            }
        }

        return ret;
    }
}
```