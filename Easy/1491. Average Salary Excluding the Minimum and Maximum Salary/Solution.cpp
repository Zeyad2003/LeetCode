class Solution {
public:
    double average(vector<int>& salary) {
        long long sum = accumulate(salary.begin(), salary.end(), 0ll); // Get the sum of all elements
        sum -= *min_element(salary.begin(), salary.end()); // Subtract minimum element
        sum -= *max_element(salary.begin(), salary.end()); // Subtract maximum element
        return (double) (sum / (double) ((int)salary.size() - 2)); // return their average.
    }
};