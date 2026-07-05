class Solution {
	public:
	int maxCharGap(string &s) {
		// code here
		int size = s.size();
		int ans = -1;
		vector<int> mp(26, -1);
		for (int i = 0; i < size; i++) {
			if (mp[s[i] - 'a'] != -1) {
				ans = max(ans, i - mp[s[i] - 'a'] - 1);
			}
			else {
				mp[s[i] - 'a'] = i;
			}
		}
		return ans;
	}
};