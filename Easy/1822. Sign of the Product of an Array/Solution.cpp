class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool foundZero = false; // To check if we found zero
        int numOfNeg = 0; // To count the number of negative numbers
        for(auto & i : nums) {
            foundZero |= !i; // If we found zero, set foundZero to true
            numOfNeg += (i < 0); // If current number is negative, increment numOfNeg
        }
        if(foundZero) return 0; // If we found zero, return 0
        if(numOfNeg & 1) return -1; // If numOfNeg is odd, return -1
        return 1; // You will have a positive product
    }
};