class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num); // Convert the number to string to deal with it more easily
        sort(s.begin(), s.end()); // Sort the string
        string num1, num2; // The final two numbers that we should build
        bool f = false; // boolean flag to check which variable we should insert the next digit into
        for(auto & i : s) { // Iterate over the string
            if(f) num1.push_back(i); // If the flag is true, insert the digit into num1
            else num2.push_back(i); // If the flag is false, insert the digit into num2
            f = !f; // Flip the flag
        }
        return stoi(num1) + stoi(num2); // Return the sum of the two numbers
    }
};