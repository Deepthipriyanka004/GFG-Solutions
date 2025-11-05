class Solution {
  public:
    int minSquares(int n) {
        // Code here
        // dp[i] denoting min num of perfect squares to make sum i
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                // checking already calculated perfect squares less than i
                dp[i] = min(dp[i], dp[i-(j*j)]+1);
            }
        }
        return dp[n];
    }
};