class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[r]) // left is sorted so min is in right
                l = mid + 1;
            else // right is sorted so min is in left
                r = mid;
        }
        return nums[l];
    }
};