class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        unordered_set<int> distinctNums;
        distinctNums.emplace(k);

        int minNum = nums[0];

        for (int i = 0; i < (int) nums.size(); i++) {
            minNum = min(minNum, nums[i]);
            distinctNums.emplace(nums[i]);
        }

        if (k > minNum) return -1;
        return (int)distinctNums.size() - 1;
    }
};
