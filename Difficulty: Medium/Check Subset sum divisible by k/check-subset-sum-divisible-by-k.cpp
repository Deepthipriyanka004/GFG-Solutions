class Solution {
	public:
	int dp[1001][1000][2];
	bool solve(int idx, int rem, vector<int> &nums, int k, int choose) {
		if (rem == 0 && choose) {
			return 1;
		}
		if (idx >= (int)nums.size()) {
			if (rem == 0 && choose)
				{
				return 1;
			}
			return 0;
		}
		if (dp[idx][rem][choose] != -1)
			{
			return dp[idx][rem][choose];
		}
		bool ans = 0;
		// not pick
		ans |= solve(idx + 1, rem, nums, k, 0);
		// pick
		ans |= solve(idx + 1, (rem + nums[idx])%k, nums, k, 1);
		return dp[idx][rem][choose] = ans;
	}
	bool divisibleByK(vector<int>& arr, int k) {
		// code here
		memset(dp, -1, sizeof(dp));
		return solve(0, 0, arr, k, 0);
	}
};