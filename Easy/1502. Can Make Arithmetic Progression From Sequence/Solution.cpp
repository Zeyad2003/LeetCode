class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0]; // Get the difference between the first two elements

        for(int i = 1; i < (int) arr.size(); i++)
            if(arr[i] - arr[i - 1] != diff) // If the difference between any other two numbers not equal to the first difference
                return false; // We can't find an arithmetic progression

        return true; // We can find an arithmetic progression
    }
};