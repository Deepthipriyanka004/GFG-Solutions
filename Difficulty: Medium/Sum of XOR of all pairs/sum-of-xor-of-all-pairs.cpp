class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long ans = 0;

        // Check each bit position
        for (int bit = 0; bit < 32; bit++) {
            long long count1 = 0;

            // Count elements with current bit set
            for (int num : arr) {
                if (num & (1 << bit)) {
                    count1++;
                }
            }

            long long count0 = n - count1;

            // Contribution of this bit
            ans += count1 * count0 * (1LL << bit);
        }

        return ans;
    }
};