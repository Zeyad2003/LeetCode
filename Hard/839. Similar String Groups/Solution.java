import java.util.*;
class Solution {
    boolean equal(String first, String second) {
        int n = first.length();
        int begin = -1, end = -1;

        for (int i = 0; i < n; i++) {
            if(first.charAt(i) != second.charAt(i)) {
                if(begin != -1) {
                    if(end != -1) return false;
                    end = i;
                } else {
                    begin = i;
                }
            }
        }
        if(begin == -1) return true;
        if(end == -1) return false;
        return (first.charAt(begin) == second.charAt(end) && first.charAt(end) == second.charAt(begin));
    }

    void dfs(HashMap<String, Vector<String> > adj, HashMap<String, Boolean> vis, String node) {
        vis.put(node, true);
        for(String i : adj.get(node)) {
            if(!vis.containsKey(i)) {
                dfs(adj, vis, i);
            }
        }
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        HashMap<String, Vector<String> > adj = new HashMap<>();
        HashMap<String, Boolean> vis = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            if(!adj.containsKey(strs[i])) adj.put(strs[i], new Vector<>());
            for (int j = i + 1; j < n; ++j) {
                if(!adj.containsKey(strs[j])) adj.put(strs[j], new Vector<>());
                if(equal(strs[i], strs[j])) {
                    adj.get(strs[i]).add(strs[j]);
                    adj.get(strs[j]).add(strs[i]);
                }
            }
        }

        int ans = 0;
        for(String i : adj.keySet()) {
            if(!vis.containsKey(i)) {
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
}