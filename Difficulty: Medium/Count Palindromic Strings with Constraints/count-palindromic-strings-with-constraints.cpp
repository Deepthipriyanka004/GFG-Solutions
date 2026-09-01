class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;
        long long ans = 0;

        // perm = P(k, m)
        long long perm = 1;

        for (int m = 0; m <= n / 2; m++) {

            if (m > 0) {
                perm = (perm * (k - m + 1)) % MOD;
            }

            // Odd length = 2*m + 1
            if (2 * m + 1 <= n) {
                // Middle character must be different
                // from all m characters in the pairs.
                ans = (ans + perm * (k - m)) % MOD;
            }

            // Even length = 2*m
            if (m > 0 && 2 * m <= n) {
                ans = (ans + perm) % MOD;
            }
        }

        return ans;
    }
};