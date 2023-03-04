class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        if(low == high) return (low & 1);
        if(low & 1) cnt++, low++; // If odd count it and move step forward
        if(high & 1) cnt++, high--; // If odd count it and move step backward
        cnt += (high - low) / 2; // count all odd numbers between them
        return cnt; // return final answer
    }
};