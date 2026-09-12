class Solution {
	public:
	int maxProduct(vector<int> &arr, int k) {
		// code here
		sort(arr.begin(), arr.end());
		int n = arr.size();
		if (k == 1) {
			return arr[n - 1];
		}
		if (arr[n - 1] <= 0 && k % 2 == 1) {
			int product = 1;
			for (int i = n - k; i < n; ++i) {
				product *= arr[i];
			}
			return product;
		}
		int left = 0;
		int right = n - 1;
		int product = 1;
		if (k % 2 == 1) {
			product *= arr[right];
			--right;
			--k;
		}
		while (k > 0) {
			int leftProduct = arr[left] * arr[left + 1];
			int rightProduct = arr[right - 1] * arr[right];
			if (leftProduct > rightProduct) {
				product *= leftProduct;
				left += 2;
			} else {
				product *= rightProduct;
				right -= 2;
			}
			k -= 2;
		}
		return product;
	}
};