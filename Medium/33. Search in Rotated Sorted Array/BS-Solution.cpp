class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int) nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid; // found the target
            if(nums[l] <= nums[mid]) { // we are in the first sorted portion
                if(target > nums[mid] or target < nums[l]) // target is in the right portion
                    l = mid + 1;
                else // target is in the left portion
                    r = mid - 1;
            } else { // we are in the second sorted portion
                if(target < nums[mid] or target > nums[r]) // target is in the left portion
                    r = mid - 1;
                else // target is in the right portion
                    l = mid + 1;
            }
        }
    }
};