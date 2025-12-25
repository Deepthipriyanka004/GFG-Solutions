class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int mx = mat[0][0];
        for (const auto& row : mat) {
            for (int val : row) {
                mx = max(mx, val);
            }
        }
        for (int y = 0; y < mat.size(); y++) {
            for (int x = 0; x < mat[y].size(); x++) {
                if (mat[y][x] == mx) {
                    return {y, x};
                }
            }
        }
        return {};
    }
};