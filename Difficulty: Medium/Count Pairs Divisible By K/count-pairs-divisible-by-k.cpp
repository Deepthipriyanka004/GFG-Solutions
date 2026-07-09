class Solution {
	public:
	int countKdivPairs(vector<int>& arr, int k) {
		// code here
		int ans = 0;
		vector<int> rem(k);
		for (int &val: arr) {
			int r = val % k;
			int left = (k - r) % k;
			ans += rem[left];
			rem[r]++;
		}
		return ans;
	}
};