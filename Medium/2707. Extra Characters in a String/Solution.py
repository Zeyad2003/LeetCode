class Solution(object):
    def __init__(self):
        self.dp = []
        self.MX = 100

    def solve(self, s, dictionary, i):
        if i >= len(s):
            return 0

        if self.dp[i] != -1:
            return self.dp[i]

        ans = self.MX

        ans = min(ans, self.solve(s, dictionary, i + 1) + 1)

        for word in dictionary:
            wordSize = len(word)
            if s[i : i + wordSize] == word:
                ans = min(ans, self.solve(s, dictionary, i + wordSize))

        self.dp[i] = ans
        return ans

    def minExtraChar(self, s, dictionary):
        self.dp = [-1] * len(s)
        return self.solve(s, dictionary, 0)
