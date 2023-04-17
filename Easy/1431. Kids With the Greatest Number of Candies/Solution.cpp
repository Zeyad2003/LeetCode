class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end()); // Find the max element in the array
        vector<bool> ans; // Used to store the answer

        for (auto & i : candies) { // Loop over the candies array
            if (i + extraCandies >= mx) ans.emplace_back(true); // If the current kid can have the max number of candies, then push true
            else ans.emplace_back(false); // Else push false
        }

        return ans; // Return the answer
    }
};