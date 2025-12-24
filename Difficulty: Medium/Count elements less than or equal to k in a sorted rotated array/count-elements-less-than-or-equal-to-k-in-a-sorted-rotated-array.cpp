class Solution {
public:
    // Binary search to count elements <= x in a sorted range
    int countInSorted(vector<int>& arr, int l, int r, int x) {
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (ans == -1) ? 0 : (ans - l + 1 + (l > r));
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;

        // Step 1: Find index of minimum element (rotation point)
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        // Step 2: Count elements <= x in both sorted halves
        int count = 0;
        count += upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();
        count += upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);

        return count;
    }
};
