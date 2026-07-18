class Solution {
public:
    static const int MOD = 1000000007;

    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        // 1. Compute 2D suffix sums to count the number of 1s in any subgrid (r...n-1, c...m-1)
        vector<vector<int>> suf(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suf[i][j] = matrix[i][j] 
                          + suf[i + 1][j] 
                          + suf[i][j + 1] 
                          - suf[i + 1][j + 1];
            }
        }

        // Base Check: If total 1s in the entire matrix is less than pieces required
        if (suf[0][0] < k) return 0;

        // dp[r][c] = number of ways to cut the subgrid from (r, c) to (n-1, m-1) into 'rem_pieces'
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: 1 piece remaining (0 cuts left)
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (suf[r][c] > 0) {
                    dp[r][c] = 1;
                }
            }
        }

        // 2. Iterate for the remaining pieces from 2 up to k
        for (int pieces = 2; pieces <= k; pieces++) {
            vector<vector<int>> next_dp(n, vector<int>(m, 0));

            // To transition in O(1), we maintain suffix sums of the *previous* DP state
            // dp_suf_row[r][c] = sum of dp[i][c] for all i from r to n-1
            // dp_suf_col[r][c] = sum of dp[r][j] for all j from c to m-1
            vector<vector<int>> dp_suf_row(n + 1, vector<int>(m, 0));
            vector<vector<int>> dp_suf_col(n, vector<int>(m + 1, 0));

            for (int r = n - 1; r >= 0; r--) {
                for (int c = m - 1; c >= 0; c--) {
                    dp_suf_row[r][c] = (dp[r][c] + dp_suf_row[r + 1][c]) % MOD;
                    dp_suf_col[r][c] = (dp[r][c] + dp_suf_col[r][c + 1]) % MOD;
                }
            }

            for (int r = n - 1; r >= 0; r--) {
                for (int c = m - 1; c >= 0; c--) {
                    if (suf[r][c] < pieces) continue; // Not enough 1s remaining to make these cuts

                    long long total_ways = 0;

                    // --- Horizontal Cuts ---
                    // Find the first row 'nr' below 'r' where the upper piece contains at least one 1.
                    // Since suf[r][c] - suf[nr][c] strictly decreases as nr increases, 
                    // the condition (suf[r][c] - suf[nr][c] > 0) is true for all nr where suf[nr][c] < suf[r][c].
                    // We can use binary search (lower_bound) to find this index in O(log N).
                    int low = r + 1, high = n - 1, first_valid_row = n;
                    while (low <= high) {
                        int mid = low + (high - low) / 2;
                        if (suf[r][c] - suf[mid][c] > 0) {
                            first_valid_row = mid;
                            high = mid - 1; // Look for an even smaller row index
                        } else {
                            low = mid + 1;
                        }
                    }
                    if (first_valid_row < n) {
                        // Sum up dp[nr][c] for all nr from first_valid_row to n-1 using our DP suffix array
                        total_ways = (total_ways + dp_suf_row[first_valid_row][c]) % MOD;
                    }

                    // --- Vertical Cuts ---
                    // Find the first column 'nc' to the right of 'c' where the left piece contains at least one 1.
                    low = c + 1, high = m - 1;
                    int first_valid_col = m;
                    while (low <= high) {
                        int mid = low + (high - low) / 2;
                        if (suf[r][c] - suf[r][mid] > 0) {
                            first_valid_col = mid;
                            high = mid - 1;
                        } else {
                            low = mid + 1;
                        }
                    }
                    if (first_valid_col < m) {
                        // Sum up dp[r][nc] for all nc from first_valid_col to m-1 using our DP suffix array
                        total_ways = (total_ways + dp_suf_col[r][first_valid_col]) % MOD;
                    }

                    next_dp[r][c] = total_ways;
                }
            }
            dp = move(next_dp);
        }

        return dp[0][0];
    }
};