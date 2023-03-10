class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = (int) arr.size();
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            int first = n - i; // Number of first elements will start from i equal to n - i
            int second = i + 1; // Number of second elements will start from i equal to i + 1
            ans += (first * second + 1) / 2 * arr[i]; // (first * second + 1) / 2 is the number of subarrays that start from i and end at j
        }

        return ans;
    }
};