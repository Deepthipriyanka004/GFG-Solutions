class Solution {
public:
    int dx[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
    int dy[8] = {2, 2, -2, -2, 1, -1, 1, -1};

    bool solve(int x, int y, int move, int n, vector<vector<int>>& board) {
        if (move == n * n) return true; // all cells visited
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1) {
                board[nx][ny] = move;
                if (solve(nx, ny, move + 1, n, board)) return true;
                board[nx][ny] = -1; // backtrack
            }
        }
        return false;
    }

    vector<vector<int>> knightTour(int n) {
        // board filled with -1
        vector<vector<int>> board(n, vector<int>(n, -1));
        if (n == 1) { board[0][0] = 0; return board; }

        // start from (0,0)
        board[0][0] = 0;
        if (solve(0, 0, 1, n, board)) return board;

        // NO solution -> return empty list (NOT {{-1}})
        return {};
    }
};
