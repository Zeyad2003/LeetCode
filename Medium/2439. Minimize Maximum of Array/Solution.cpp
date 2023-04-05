class Solution {
public:

    bool can(vector<long long> arr, int limit) {
        int n = (int) arr.size(); // Get the size of the array

        for(int i = n - 1; i > 0; i--) { // For every element in the array
            long long diff = arr[i] - limit; // Get the difference between current number and the max limit
            if(diff > 0) { // True -> We need to decrease this number
                arr[i] -= diff; // Decrease the current number
                arr[i - 1] += diff; // Put the difference in the previous number
            }
        }

        return all_of(arr.begin(), arr.end(), [&](auto i) { // Check if all the numbers are less than or equal to the limit
            return i <= limit;
        });
    }

    int minimizeArrayValue(vector<int> &nums) {
        int l = 0, r = 1e9, ans;
        vector<long long> arr(nums.begin(), nums.end()); // Copy the array to a long long array

        while(l <= r) {
            int mid = l + (r - l) / 2; // Assume the mid as the max limit
            if(can(arr, mid)) { // True -> Try to decrease the array value
                ans = mid;
                r = mid - 1;
            } else l = mid + 1; // False -> Try to increase the array value
        }

        return ans; // Return the minimum array value
    }
};