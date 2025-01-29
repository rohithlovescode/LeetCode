class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1, 0},  {-1, 0}, {0, 1}, {0, -1},
                               {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    bool isSafe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        m = board.size(), n = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> pq;
        pq.push({click[0], click[1]});
        visited[click[0]][click[1]] = true;
        while (!pq.empty()) {
            auto curr = pq.front();
            pq.pop();
            // we can only click on 'M' or 'E'
            int x = curr[0], y = curr[1];
            // you land on unrevealed empty block
            int minesCount = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (isSafe(nx, ny) && board[nx][ny] == 'M') minesCount++;
            }
            if (minesCount) board[x][y] = 48 + minesCount;
            else {
                board[x][y] = 'B';
                for (int i = 0; i < 8; i++) {
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if (isSafe(nx, ny) && !visited[nx][ny]) {
                        pq.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return board;
    }
};

// If we click on M then simply make it X
// if E is clicked with NO ADJACENT MINES make it B
// otherwise count adjacent mines and give that number to it.

// what all options I got
// M is unrevealed MINE
// E is unrevealed EMPTY BLOCK
// B is revealed already with NO Adjacent MINES
// digit 1-8 are how many mines are adjacent to this revealed square B