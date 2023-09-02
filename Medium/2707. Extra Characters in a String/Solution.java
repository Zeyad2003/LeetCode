class Solution {
    public int [] dp;
    final int MX = 100;

    public int solve(String s, String[] dictionary, int i) {
        if(i >= s.length()) return 0;

        if(dp[i] != -1) return dp[i];
        int ret = MX;

        ret = Math.min(ret, solve(s, dictionary, i + 1) + 1);
        for(String word : dictionary) {
            int wordSize = word.length();
            String sub = s.substring(i, Math.min(i + wordSize, s.length()));
            if(sub.equals(word))
                ret = Math.min(ret, solve(s, dictionary, i + wordSize));
        }

        return dp[i] = ret;
    }

    public int minExtraChar(String s, String[] dictionary) {
        dp = new int[s.length() + 1];
        Arrays.fill(dp, -1);
        return solve(s, dictionary, 0);
    }
}