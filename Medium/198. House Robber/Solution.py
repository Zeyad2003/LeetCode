class Solution(object):
    def rob(self, nums):
        sz = len(nums)
        dp = [-1] * 101

        def solve(i):
            if i >= sz:
                return 0
            if dp[i] != -1:
                return dp[i]
            dp[i] = max(solve(i + 1), nums[i] + solve(i + 2))
            return dp[i]
        
        return solve(0)
