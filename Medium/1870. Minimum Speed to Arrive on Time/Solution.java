class Solution {
    final int oo = 10000005;

    boolean can(int[] dist, double hour, int mid) {
        int n = dist.length;
        double ret = 0;

        for(int i = 0; i < n - 1; i++) {
            double val = (double) dist[i] / (double) mid;
            val = Math.ceil(val);
            ret += val;
        }
        ret += (double) dist[n - 1] / (double) mid;

        return ret <= hour;
    }

    public int minSpeedOnTime(int[] dist, double hour) {
        int ans = oo;
        int l = 1, r = oo, mid;

        while(l <= r) {
            mid = (l + r) / 2;
            if(can(dist, hour, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return (ans == oo ? -1 : ans);
    }
}