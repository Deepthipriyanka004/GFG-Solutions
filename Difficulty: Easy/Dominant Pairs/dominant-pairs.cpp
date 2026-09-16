class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int half = n / 2;

        // Sort the second half
        sort(arr.begin() + half, arr.end());

        long long count = 0;

        for (int i = 0; i < half; i++) {
            // Find first position where 5 * arr[j] > arr[i]
            int low = half, high = n;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if ((long long)arr[mid] * 5 <= arr[i]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            // All elements from half to low-1 are valid
            count += (low - half);
        }

        return count;
    }
};