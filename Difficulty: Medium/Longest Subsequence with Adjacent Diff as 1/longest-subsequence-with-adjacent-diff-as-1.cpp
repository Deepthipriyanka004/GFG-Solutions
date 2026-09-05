class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int, int> dp;
        int ans = 0;
        for (int x : arr) {
            int left = dp.count(x - 1) ? dp[x - 1] : 0;
            int right = dp.count(x + 1) ? dp[x + 1] : 0;
            int current = max(left, right) + 1;
            dp[x] = current;
            ans = max(ans, current);
        }
        return ans;
    }
};