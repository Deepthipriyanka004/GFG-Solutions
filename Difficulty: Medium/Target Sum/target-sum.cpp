class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        // Edge cases
        if ((target + totalSum) % 2 != 0) return 0;
        if (abs(target) > totalSum) return 0;

        int sum = (target + totalSum) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int j = sum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[sum];
    }
};