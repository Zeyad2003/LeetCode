class Solution {
public:
    const int MX = 1e5 + 5; // Max size for the range of numbers
    const int  offset = 5e4; // To handle negative vlaues

    vector<int> sortArray(vector<int>& nums) {
        // Create a counting array of size MX
        int cnt[MX];

        // Initialize all elements of cnt to 0
        memset(cnt, 0, sizeof(cnt));

        // Traverse on nums and increment the count of nums[i]
        for(auto & i : nums) 
            cnt[i + offset]++; // We shift numbers to make negative numbers in positive indices

        // Traverse on cnt and copy the elements back into nums in sorted order
        for(int i = 0, j = 0; i < MX; i++)
            while(cnt[i]--) 
                nums[j++] = i - offset; // Apply the opposite shift operation to put the right value

        return nums;
    }
};