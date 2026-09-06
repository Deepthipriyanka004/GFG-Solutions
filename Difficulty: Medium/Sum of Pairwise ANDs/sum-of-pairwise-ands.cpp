class Solution {
	public:
	long long pairAndSum(vector<int> &arr) {
		// code here
		int n = arr.size();
		long long ans = 0;
		for (int i = 0 ; i<32 ; i++) {
			long long cnt = 0;
			for (int j = 0 ; j<n ; j++) {
				cnt += (arr[j]>> i) & 1;
			}
			if (cnt>1)
				ans += (1 << i) * (cnt*(cnt - 1))/2;
		}
		return ans;
	}
};