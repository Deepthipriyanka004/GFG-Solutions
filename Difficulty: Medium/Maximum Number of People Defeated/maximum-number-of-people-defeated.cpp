class Solution {
public:
    int maxPeopleDefeated(int p) {
        long long low = 0, high = 10000;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;

            if (sum <= p) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};