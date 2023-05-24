class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = (int) nums1.size();
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i++) v.emplace_back(nums2[i], nums1[i]);
        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0, ans = 0;

        for(int i = 0; i < k - 1; i++) {
            pq.emplace(v[i].second);
            sum += v[i].second;
        }

        for(int i = k - 1; i < n; i++) {
            sum += v[i].second;
            pq.emplace(v[i].second);
            ans = max(ans, sum * v[i].first);

            sum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};