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