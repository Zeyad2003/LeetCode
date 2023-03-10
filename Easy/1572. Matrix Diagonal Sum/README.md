# [1572. Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

## Solution
- Loop through the matrix and add the sum of the diagonal elements and the anti-diagonal elements.
- If the matrix is odd, we need to subtract the middle element, because it appears twice.
## Complexity
- Time Complexity: `O(n)`, where `n` is the length of the array.

- Space Complexity: `O(1)`


## Code
```
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
```