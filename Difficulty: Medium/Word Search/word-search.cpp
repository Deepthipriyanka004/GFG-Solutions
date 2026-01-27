class Solution {
  public:
    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};
    bool dfs(int ind, int row, int col, vector<vector<char>>& mat, int n, int m,
             string& word, vector<vector<int>>& vis) {
        if (ind == word.size())
            return true;
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                mat[nRow][nCol] == word[ind] && vis[nRow][nCol] == -1) {
                vis[nRow][nCol] = 1;
                if (dfs(ind + 1, nRow, nCol, mat, n, m, word, vis))
                    return true;
                vis[nRow][nCol] = -1;
            }
        }
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (dfs(1, i, j, mat, n, m, word, vis))
                        return true;
                    vis[i][j] = -1;
                }
            }
        }
        return false;
    }
};