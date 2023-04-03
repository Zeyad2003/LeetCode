class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = (int) people.size(); // Get the size of the people vector
        sort(people.begin(), people.end()); // Sort the vector in ascending order
        int cnt = 0; // Used to count the minimum number of boats
        int l = 0, r = n - 1; // Set your bounds

        while(l <= r) { // While not finished all people
            cnt++; // Take a boat
            if(people[r] + people[l] > limit) r--; // You can't take both people, so take the heaviest one
            else l++, r--; // You can take both
        }

        return cnt; // Return the minimum number of boats
    }
};