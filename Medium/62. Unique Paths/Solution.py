class Solution(object):
    def __init__(self):
        self.dp = []
    
    def out(self, m, n, i, j):
        return i < 0 or j < 0 or i >= m or j >= n; 

    def solve(self, m, n, i, j):
        if i == m - 1 and j == n - 1:
            return 1

        ret = self.dp[i][j]

        if ret != -1:
            return ret

        ret = 0
        if not self.out(m, n, i + 1, j):
            ret += self.solve(m, n, i + 1, j)
        if not self.out(m, n, i, j + 1):
            ret += self.solve(m, n, i, j + 1)

        self.dp[i][j] = ret
        return ret
    
    
    def uniquePaths(self, m, n):
        self.dp = [[-1 for col in range(n)] for row in range(m)]
        return self.solve(m, n, 0, 0)
