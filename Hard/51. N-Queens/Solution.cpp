class Solution {
public:
    int N; // size of board
    vector<vector<string> > ans; // our answer
    vector<bool> rows, cols, posDiag, negDiag; // to check if a queen can be placed at a particular position

    bool valid(int r, int c) { // check if a queen can be placed at (r, c)
        return rows[r] and cols[c] and posDiag[r + c] and negDiag[r - c + 9];
    }

    void update(vector<string> &board, int r, int c) { // update the board and the vectors after placing a queen at (r, c)
        board[r][c] = 'Q';
        rows[r] = false;
        cols[c] = false;
        posDiag[r + c] = false;
        negDiag[r - c + 9] = false;
    }

    void undo(vector<string> &board, int r, int c) { // undo the changes made by update()
        board[r][c] = '.';
        rows[r] = true;
        cols[c] = true;
        posDiag[r + c] = true;
        negDiag[r - c + 9] = true;
    }

    void backtrack(vector<string> &board, int r) { // backtrack function
        if(r == N) { // if we have placed N queens
            ans.emplace_back(board); // add the current board to the answer
            return; // and return
        }

        for(int c = 0; c < N; c++) { // try to place a queen at each column of the current row
            if(valid(r, c)) { // if a queen can be placed at (r, c)
                update(board, r, c); // update the board and the vectors
                backtrack(board, r + 1); // backtrack on the next row
                undo(board, r, c); // undo the changes made by update()
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n; // set the size of the board
        vector<string> board(n, string(n, '.')); // create an empty board
        rows = cols = posDiag = negDiag = vector<bool> (n + 10, true); // initialize the vectors

        backtrack(board, 0); // start backtracking from the first row

        return ans; // return the answer
    }
};