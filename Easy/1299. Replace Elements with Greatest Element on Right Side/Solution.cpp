class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // The first next greater element will be the last element in the array
        int nxtG = arr.back();

        int n = (int) arr.size(); // array size

        // The last element in the array will always be replaced with -1, as there is no elements after it
        arr[n - 1] = -1;

        // Loop through the array backwards
        for(int i = n - 2; i >= 0; i--) {
            // Save the current element to check if it will be used as the next greater element
            int tmp = arr[i];

            // Set the current element of the input vector to the next greater element
            arr[i] = nxtG;

            // Update the nxtG with the max value
            nxtG = max(nxtG, tmp);
        }

        return arr;
    }
};