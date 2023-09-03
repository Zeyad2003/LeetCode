let dp;
var uniquePaths = function (m, n) {
  dp = Array.from({ length: m }, () => Array(n).fill(-1));
  return solve(m, n, 0, 0);
};

let out = (m, n, i, j) => {
  return i < 0 || j < 0 || i >= m || j >= n;
};

let solve = (m, n, i, j) => {
  if (i == m - 1 && j == n - 1) return 1;

  let ret = dp[i][j];
  if (ret != -1) return ret;

  ret = 0;
  if (!out(m, n, i + 1, j)) ret += solve(m, n, i + 1, j);
  if (!out(m, n, i, j + 1)) ret += solve(m, n, i, j + 1);
  return (dp[i][j] = ret);
};
