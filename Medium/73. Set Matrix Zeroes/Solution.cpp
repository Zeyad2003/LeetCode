class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size(); // Get the size of the matrix.
        set<int> rows, cols; // Store the rows and columns that have 0s.

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(!matrix[i][j]) { // Found a 0.
                    rows.insert(i); // Store the row.
                    cols.insert(j); // Store the column.
                }
            }
        }

        for(auto & i : rows) // Loop through the rows you stored and update them with 0.
            for (int j = 0; j < m; ++j)
                matrix[i][j] = 0;

        for(auto & j : cols) // Loop through the columns you stored and update them with 0.
            for (int i = 0; i < n; ++i)
                matrix[i][j] = 0;

    }
};