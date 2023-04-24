import java.util.*;
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        for (int i : stones) q.add(i);

        while (q.size() > 1) {
            int y = q.peek();
            q.poll();
            int x = q.peek();
            q.poll();
            if (x != y) q.add(y - x);
        }

        if (q.size() > 0) return q.peek();
        else return 0;
    }
}