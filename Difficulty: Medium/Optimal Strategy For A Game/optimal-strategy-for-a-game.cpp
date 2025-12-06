class Solution {
public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        static long long dp[2001][2001]; // Assumes max n <= 2000 (given in problem)
        
        for(int i = 0; i < n; i++)
            dp[i][i] = arr[i];

        for(int len = 2; len <= n; len++) {
            for(int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                long long chooseL = arr[l] + min(
                    (l+2 <= r ? dp[l+2][r] : 0),
                    (l+1 <= r-1 ? dp[l+1][r-1] : 0)
                );

                long long chooseR = arr[r] + min(
                    (l+1 <= r-1 ? dp[l+1][r-1] : 0),
                    (l <= r-2 ? dp[l][r-2] : 0)
                );

                dp[l][r] = max(chooseL, chooseR);
            }
        }

        return dp[0][n-1];
    }
};
