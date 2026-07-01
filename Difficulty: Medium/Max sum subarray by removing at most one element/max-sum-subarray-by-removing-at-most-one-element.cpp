class Solution {
	public:
	int maxSumSubarray(vector<int>& arr) {
		// code here
		vector<int> forwardKadans(arr.size(), 0);
		vector<int> backWardKadans(arr.size(), 0);
		forwardKadans[0] = arr[0];
		int maxi = arr[0];
		for (int i = 1; i<arr.size(); i++) {
			maxi = max(arr[i], arr[i]+ maxi);
			forwardKadans[i] = maxi;
		}
		maxi = arr[arr.size() - 1];
		backWardKadans[arr.size() - 1] = arr[arr.size() - 1];
		for (int i = arr.size() - 2; i >= 0; i--) {
			maxi = max(arr[i], arr[i] + maxi);
			backWardKadans[i] = maxi;
		}
		// Without any removal
		int ans = INT_MIN;
		for (int i = 0; i<arr.size(); i++) {
			ans = max(ans, forwardKadans[i]);
		}
		// With removal
		for (int i = 1; i<arr.size() - 1; i++) {
			ans = max(ans, forwardKadans[i - 1] +backWardKadans[i + 1]);
		}
		return ans;
	}
};