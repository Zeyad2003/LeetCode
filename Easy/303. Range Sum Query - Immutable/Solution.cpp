class NumArray {
public:
    vector<int> pre; // prefix sum array
    NumArray(vector<int>& nums) { // Prepare prefix sum array
        pre.emplace_back(nums[0]);
        for(int i = 1; i < (int) nums.size(); i++)
            pre.emplace_back(nums[i] + pre.back());
    }

    int sumRange(int left, int right) {
        if(!left) return pre[right]; // if left is 0, pre[right] is the answer
        return pre[right] - pre[left - 1]; // else, get the prefix sum of the range
    }
};