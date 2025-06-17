class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        // Prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        // Suffix sum
        vector<long long> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + arr[i];
        }
        long long minCoins = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int maxAllowed = arr[i] + k;
            // Binary search to find first index where arr[j] > maxAllowed
            int left = i, right = n - 1, idx = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid] > maxAllowed) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            long long leftCoins = prefix[i];  // Remove all piles before index i
            long long rightCoins = 0;
            if (idx < n) {
                long long total = suffix[idx];
                long long target = 1LL * (n - idx) * maxAllowed;
                rightCoins = total - target;
            }
            minCoins = min(minCoins, leftCoins + rightCoins);
        }
        return static_cast<int>(minCoins);
    }
};