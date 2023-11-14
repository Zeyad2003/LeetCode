var countPalindromicSubsequence = function(s) {
  let st = new Set();
  let n = s.length, ans = 0;

  for(let i = 0; i < n; i++) {
      if(!st.has(s[i])) {
          st.add(s[i]);
          let lastIdx = s.lastIndexOf(s[i]);
          if(lastIdx != i) {
              let cntDistinct = new Set(s.slice(i + 1, lastIdx));
              ans += cntDistinct.size;
          }
      }
  }

  return ans;
};
