class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for(auto & i : accounts) { // For every customer
            int sum = accumulate(i.begin(), i.end(), 0); // Sum of his accounts
            ans = max(ans, sum); // Update the answer with the maximum sum
        }

        return ans;
    }
};