class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int) nums.size() - 1; // Set your pointers
        while(l <= r) {
            int mid = l + (r - l) / 2; // Get the mid element
            if(nums[mid] == target) return mid; // We found the element
            else if(nums[mid] > target) r = mid - 1; // Bigger than target -> Search on the left side
            else l = mid + 1; // Smaller than the target -> Search on the right side
        }
        return -1; // Didn't find the target in the array
    }
};