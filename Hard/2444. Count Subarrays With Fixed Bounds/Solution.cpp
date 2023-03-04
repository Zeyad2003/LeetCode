class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = (int) nums.size();
        long long ans = 0;

        int mnIdx = -1, mxIdx = -1, bound = -1;
        for (int i = 0; i < n; ++i) {
            if(nums[i] < minK or nums[i] > maxK)
                bound = i; // make any subarray invalid so start counting from the next element
            if(nums[i] == minK)
                mnIdx = i; // find the max idx for minK
            if(nums[i] == maxK)
                mxIdx = i; // find the max idx for maxK

            // if you have both minK and maxK, then it causes min(mnIdx, mxIdx) - bound subarrays
            ans += max(0, min(mnIdx, mxIdx) - bound);
        }
        return ans;
    }
};