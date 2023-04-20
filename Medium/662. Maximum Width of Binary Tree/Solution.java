import java.util.*;
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        long M = 10000000000L;
        Map<TreeNode, Long> mp = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        mp.put(root, 0L);
        int ans = 0;
        for(int level = 0; !q.isEmpty(); level++) {
            int sz = q.size();
            Vector<TreeNode> v = new Vector<>();
            for(int i = 0; i < sz; i++){
                TreeNode curNode = q.peek();
                long idx = mp.get(curNode);
                q.remove();
                v.add(curNode);
                if(curNode.left != null) {
                    mp.put(curNode.left, (2 * idx + 1) % M);
                    q.add(curNode.left);
                }
                if(curNode.right != null) {
                    mp.put(curNode.right, (2 * idx + 2) % M);
                    q.add(curNode.right);
                }
            }

            int val = (int) (mp.get(v.get(v.size() - 1)) - mp.get(v.get(0))) + 1;
            ans = Math.max(ans, val);
        }
        return ans;
    }
}