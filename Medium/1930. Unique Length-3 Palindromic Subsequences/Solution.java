class Solution {
    public int countPalindromicSubsequence(String s) {
        Set<Character> st = new HashSet<>();
        int n = s.length(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            if(!st.contains(s.charAt(i))) {
                st.add(s.charAt(i));
                int lastIdx = s.lastIndexOf(s.charAt(i));
                if (lastIdx != i) {
                    Set<Character> cntDistinct = new HashSet<>();
                    for (int j = i + 1; j < lastIdx; j++) cntDistinct.add(s.charAt(j));
                    ans += cntDistinct.size();
                }
            }
        }
        
        return ans;
    }
}
