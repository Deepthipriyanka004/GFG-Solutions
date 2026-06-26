class Solution {
	public:
	int mod = 1e9 + 7;
	int solve(int i, int j, string a, string b, vector<vector<int>> &dp) {
		if (i >= a.size()) {
			return j >= b.size();
		}
		if (j >= b.size())
			return 1;
		if (dp[i][j] != -1)
			return dp[i][j];
		int ans = 0;
		if (a[i] == b[j]) {
			ans += solve(i + 1, j + 1, a, b, dp);
		}
		ans += solve(i + 1, j, a, b, dp);
		return dp[i][j] = ans%mod;
	}
	int countWays(string &s1, string &s2) {
		// code here
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
		return solve(0, 0, s1, s2, dp);
	}
};