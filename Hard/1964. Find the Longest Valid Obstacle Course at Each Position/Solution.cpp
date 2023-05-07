class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = (int) obstacles.size();
        vector<int> dp, ret(n);

        for(int i = 0; i < n; i++){
            if(dp.empty() or dp.back() <= obstacles[i]) {
                dp.emplace_back(obstacles[i]);
                ret[i] = (int)dp.size();
            } else {
                auto it = upper_bound(dp.begin(), dp.end(), obstacles[i]);
                *it = obstacles[i];
                ret[i] = it - dp.begin() + 1;
            }
        }

        return ret;
    }
};