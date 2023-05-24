class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] v = new int[n][2];
        for(int i = 0; i < n; i++) v[i] = new int[] {nums2[i], nums1[i]};
        Arrays.sort(v, (a, b) -> b[0] - a[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0, ans = 0;

        for(int i = 0; i < k - 1; i++) {
            pq.add(v[i][1]);
            sum += v[i][1];
        }

        for(int i = k - 1; i < n; i++) {
            sum += v[i][1];
            pq.add(v[i][1]);
            ans = Math.max(ans, sum * v[i][0]);

            if(!pq.isEmpty()) sum -= pq.poll();
        }

        return ans;
    }
}