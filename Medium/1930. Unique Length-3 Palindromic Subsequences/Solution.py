class Solution(object):
    def countPalindromicSubsequence(self, s):
        st = set()
        ans = 0

        for i in range(len(s)):
            if s[i] not in st:
                st.add(s[i])
                lastIdx = s.rfind(s[i])
                if lastIdx != i:
                    cntDistinct = set(s[i + 1:lastIdx])
                    ans += len(cntDistinct)

        return ans
    