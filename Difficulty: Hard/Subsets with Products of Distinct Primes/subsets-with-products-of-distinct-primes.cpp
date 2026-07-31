class Solution {
public:
    int countSubsets(vector<int> &arr) {
        const int MOD = 1000000007;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        vector<int> freq(31, 0);
        for (int x : arr) freq[x]++;

        int ones = freq[1];

        vector<int> masks(31, -1);

        for (int x = 2; x <= 30; x++) {
            int t = x;
            int mask = 0;
            bool ok = true;

            for (int i = 0; i < 10; i++) {
                int p = primes[i];
                int cnt = 0;
                while (t % p == 0) {
                    t /= p;
                    cnt++;
                }
                if (cnt > 1) {
                    ok = false;
                    break;
                }
                if (cnt == 1)
                    mask |= (1 << i);
            }

            if (ok) masks[x] = mask;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int x = 2; x <= 30; x++) {
            if (freq[x] == 0 || masks[x] == -1) continue;

            int m = masks[x];
            vector<long long> ndp = dp;

            for (int mask = 0; mask < (1 << 10); mask++) {
                if ((mask & m) == 0) {
                    ndp[mask | m] =
                        (ndp[mask | m] + dp[mask] * 1LL * freq[x]) % MOD;
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int mask = 1; mask < (1 << 10); mask++)
            ans = (ans + dp[mask]) % MOD;

        long long pow2 = 1;
        while (ones--) pow2 = (pow2 * 2) % MOD;

        ans = (ans * pow2) % MOD;
        return (int)ans;
    }
};