class Solution(object):
    def __init__ (self):
        self.dp = []

    def solve(self, nums, target, val):
        if val > target:
            return 0
        if val == target:
            return 1

        if self.dp[val] != -1:
            return self.dp[val]

        ret = 0
        
        for it in nums:
            ret += self.solve(nums, target, val + it)

        self.dp[val] = ret
        return ret


    def combinationSum4(self, nums, target):
        self.dp = [-1] * (target)
        return self.solve(nums, target, 0)
