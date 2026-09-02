class Solution {
	public:
	int solve(int n, string s) {
		// code here
		int ans = 0;
		unordered_map<char, int> mp;
		for (auto i:s) {
			if (!mp[i]) {
				if (n>0) {
					mp[i] = 1;
					n--;
				} else {
					mp[i] = -1;
					ans++;
				}
			} else {
				if (mp[i] == -1)
					continue;
				mp[i] = 0;
				n++;
			}
		}
		return ans;
	}
};