class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend()); // Sort in non-increasing order

        for(int i = 0; i + 2 < (int) nums.size(); i++)
            if(nums[i] < nums[i + 1] + nums[i + 2]) // The largest side is smaller than the sum of the other two sides -> Valid Triangle
                return nums[i] + nums[i + 1] + nums[i + 2]; // Return the perimeter

        return 0; // No valid triangle found
    }
};