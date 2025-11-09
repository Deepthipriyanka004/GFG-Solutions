class Solution {
  public:
    int n;
    vector<vector<vector<int>>> dp;
    
    // Recursive helper function with memoization
    int solve(vector<vector<int>> &mat, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;  // since both robots take the same number of steps
        
        // Check boundaries and blocked cells
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return INT_MIN;
        if (mat[r1][c1] == -1 || mat[r2][c2] == -1) return INT_MIN;
        
        // Base case: reached destination
        if (r1 == n - 1 && c1 == n - 1) return mat[r1][c1];
        
        // If already computed
        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        
        int chocolates = mat[r1][c1];
        // If both robots are not on the same cell, add chocolates from both
        if (r1 != r2 || c1 != c2)
            chocolates += mat[r2][c2];
        
        // Explore 4 possible move combinations
        int next = max({
            solve(mat, r1 + 1, c1, r2 + 1), // down, down
            solve(mat, r1, c1 + 1, r2),     // right, right
            solve(mat, r1 + 1, c1, r2),     // down, right
            solve(mat, r1, c1 + 1, r2 + 1)  // right, down
        });
        
        // Add collected chocolates and store result
        chocolates += next;
        return dp[r1][c1][r2] = chocolates;
    }
    
    int chocolatePickup(vector<vector<int>> &mat) {
        n = mat.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int result = solve(mat, 0, 0, 0);
        // If no valid path exists, return 0
        return max(0, result);
    }
};
