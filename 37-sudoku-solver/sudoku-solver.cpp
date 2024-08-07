class Solution {
public:
    bool canPlace(vector<vector<char>> board, char n, int row, int col) {
        for (auto c : board[row]) {
            if (c == n)
                return false;
        }
        int effCol;
        int effRow;

        if (col < 3)
            effCol = 0;
        else if (col < 6)
            effCol = 3;
        else
            effCol = 6;

        if (row < 3)
            effRow = 0;
        else if (row < 6)
            effRow = 3;
        else
            effRow = 6;

        for (int i = effRow; i < effRow + 3; i++) {
            for (int j = effCol; j < effCol + 3; j++) {
                if (board[i][j] == n)
                    return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == n)
                return false;
        }
        return true;

        // Another Approach
        //  for(int i=0;i<9;i++)
        //  {
        //      if(board[i][col]==c)return false;
        //      if(board[row][i]==c)return false;
        //      if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
        //  }
        //  return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (canPlace(board, c, i, j)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};