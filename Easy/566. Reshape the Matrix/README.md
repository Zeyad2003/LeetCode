# [566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/)

## Solution
- First, check if the matrix can be reshaped, by checking this condition: `r * c == nums.length * nums[0].length`
- Second, iterate on the original matrix and put the elements into the new matrix by using new two iterators for the new matrix.
## Complexity
- Time Complexity: `O(nm)`, where `n` is the length of the array, and `m` is the length of array[0].

- Space Complexity: `O(nm)`, the size of the output array.


## Code
```
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        if(n * m != r * c) return mat; // Can't reshape
        vector<vector<int> > ret(r, vector<int>(c)); // New Matrix

        int row = 0, col = 0; // New Matrix Iterators
        for (int i = 0; i < n; ++i) { // Loop over the old Matrix
            for (int j = 0; j < m; ++j) {
                ret[row][col++] = mat[i][j]; // Copy the elements to the new one
                if(col == c) { // If we reach the end of the row, update the iterators
                    col = 0;
                    row++;
                }
            }
        }

        return ret; // Return the new Matrix
    }
};
```