class Solution {
public:

    // Binary Search Function that return the index of the element we are looking for or -1 if not found
    int binarySearch(vector<int> &nums, int l, int r, int target) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid; // Found the element
        if (nums[mid] > target) return binarySearch(nums, l, mid - 1, target); // Search in the left half
        return binarySearch(nums, mid + 1, r, target); // Search in the right half
    }

    int search(vector<int> &nums, int target) {
        int n = (int) nums.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] > nums[i + 1]) { // Find the pivot point
                int ans = binarySearch(nums, 0, i, target);
                if (ans != -1) // Found in the left half
                    return ans;
                return binarySearch(nums, i + 1, n - 1, target); // Check if found in the right half
            }
        }
        return binarySearch(nums, 0, n - 1, target); // If the array is not rotated
    }
};