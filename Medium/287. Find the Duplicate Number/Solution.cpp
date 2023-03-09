class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true) { // still looping until detect the cycle
            slow = nums[slow]; // 1x
            fast = nums[fast];
            fast = nums[fast]; // 2x
            if(slow == fast) { // cycle detected
                fast = 0; // reset fast to head
                while(fast != slow) { // keep moving until they meet again at the start of the cycle
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return fast; // return the start of the cycle
            }
        }
        return 0;
    }
};