class Solution {
public:
    const int oo = 1e7 + 5;

    bool can(vector<int> &dist, double hour, int mid) {
        int n = (int) dist.size();
        double ret = 0;

        for(int i = 0; i < n - 1; i++) {
            double val = (double) dist[i] / (double) mid;
            val = ceil(val);
            ret += val;
        }
        ret += (double) dist[n - 1] / (double) mid;

        return ret <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
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
};