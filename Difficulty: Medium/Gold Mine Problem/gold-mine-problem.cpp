class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        for (int c = 1; c < n; ++c) {
            for (int r = 0; r < m; ++r) {
                int val = mat[r][c - 1];
                if (r - 1 >= 0)
                    val = max(val, mat[r - 1][c - 1]);
                if (r + 1 < m)
                    val = max(val, mat[r + 1][c - 1]);

                mat[r][c] += val;
            }
        }
        int maxGold = 0;
        for (int r = 0; r < m; ++r)
            maxGold = max(maxGold, mat[r][n - 1]);
        return maxGold;
    }
};