class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = (int) nums.size();
        set<int> st;

        // for each element in nums => put the max value it can reach
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) nums[i] <<= 1; // max value this element can reach
            st.insert(nums[i]);
        }

        int ans = *st.rbegin() - *st.begin(); // get difference between max and min

        // if max become odd we can't replace it by any other value less than it
        // st.begin() -> min value && st.rbegin() -> max value
        while (*st.rbegin() % 2 == 0) {
            int x = *st.rbegin(); // get max
            st.erase(x); // remove max
            st.insert(x >> 1); // update max with its half
            ans = min(ans, *st.rbegin() - *st.begin()); // update ans with minimum difference
        }

        return ans;
    }
};