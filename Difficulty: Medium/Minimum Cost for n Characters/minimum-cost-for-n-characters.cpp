class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int x = 1; x <= n; x++) {
            dp[x] = dp[x - 1] + i; // insert 1 char
            if (x % 2 == 0) { // build x/2, copy paste to get x
                dp[x] = min(dp[x], dp[x / 2] + c);
            } else {
                // build (x-1)/2, copy, then insert 1
                dp[x] = min(dp[x], dp[x / 2] + c + i);
                // build (x+1)/2, copy, then delete 1
                dp[x] = min(dp[x], dp[x / 2 + 1] + c + d);
            }
        }
        return dp[n];
    }
};