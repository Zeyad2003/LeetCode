class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = (int) mat.size();
        int firstDiagonal = 0, secondDiagonal = 0;
        for(int i = 0; i < n; i++) {
            firstDiagonal += mat[i][i]; // first diagonal
            secondDiagonal += mat[i][n - i - 1]; // second diagonal
        }
        if(n & 1) secondDiagonal -= mat[n / 2][n / 2]; // if n is odd, we need to subtract the middle element
        return firstDiagonal + secondDiagonal; // return the sum of both diagonals
    }
};