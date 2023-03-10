class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)nums.size();
        int zeroPointer = 0; // Used to track the position of the last zero you can reach from your position when you meet a zero

        for(int i = 0; i < n; i++) {
            if(!nums[i]) { // Meet a zero
                zeroPointer = max(zeroPointer, i); // Update the zero pointer to the max position it can reach
                while(!nums[zeroPointer] and zeroPointer + 1 < n) // Find the next non zero element
                    zeroPointer++;
                swap(nums[i], nums[zeroPointer]); // Swap the zero with the next non zero element
            }
        }
    }
};