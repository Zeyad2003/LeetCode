# [2140. Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/)

## Solution:
- Use `Dynamic Programming` to calculate the maximum profit you can get by taking the best subsequence of `questions`.
- Just follow the pick or leave approach.
- For every question, you have two choices:
    - Pick the current question then take its profit `questions[i][0]` and move to the next valid question after leaving `questions[i][1]` questions.
    - Leave the current question and move to the next question.

## Complexity
- Time Complexity: `O(N)`, where `N` is the length of `questions`.
- Space Complexity: `O(N)`, for the `dp` array.

## Code
### C++
```cpp
class Solution {
public:
    long long dp[100001];

    long long solve(vector<vector<int> > &questions, int i = 0) {
        if(i >= (int) questions.size()) return 0;

        auto & ret = dp[i];
        if(~ret) return ret;

        ret = solve(questions, i + 1);
        ret = max(ret, questions[i][0] + solve(questions, i + questions[i][1] + 1));

        return ret;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof dp);
        return solve(questions);
    }
};
```

### Java
```java
class Solution {
    long[] dp = new long[100001];

    long solve(int[][] questions, int i) {
        if(i >= questions.length) return 0;
        if(dp[i] != -1) return dp[i];

        long ret = solve(questions, i + 1);
        ret = Math.max(ret, questions[i][0] + solve(questions, i + questions[i][1] + 1));

        return dp[i] = ret;
    }

    public long mostPoints(int[][] questions) {
        Arrays.fill(dp, -1);
        return solve(questions, 0);
    }
}
```