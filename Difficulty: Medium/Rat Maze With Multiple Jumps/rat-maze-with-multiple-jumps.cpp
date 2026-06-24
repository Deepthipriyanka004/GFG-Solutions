class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<int>>& path) {

        if (i == n - 1 && j == n - 1) {
            path[i][j] = 1;
            return true;
        }

        if (mat[i][j] == 0)
            return false;

        if (dp[i][j] == 0)
            return false;

        path[i][j] = 1;

        int jump = mat[i][j];

        for (int k = 1; k <= jump; k++) {

            // Right first
            if (j + k < n) {
                if (dfs(i, j + k, mat, path))
                    return true;
            }

            // Down
            if (i + k < n) {
                if (dfs(i + k, j, mat, path))
                    return true;
            }
        }

        path[i][j] = 0;
        dp[i][j] = 0; // cannot reach destination from here
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        n = mat.size();

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> path(n, vector<int>(n, 0));
        dp.assign(n, vector<int>(n, 1));

        if (dfs(0, 0, mat, path))
            return path;

        return {{-1}};
    }
};