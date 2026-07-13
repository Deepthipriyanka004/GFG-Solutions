class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int minOperations(vector<int>& b) {
        int n = b.size();
        vector<bool> vis(n, false);
        map<int, int> primeExp;

        // Find cycle lengths
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cur = i;
                int len = 0;

                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = b[cur] - 1; // convert to 0-based indexing
                    len++;
                }

                // Factorize cycle length
                int x = len;
                for (int p = 2; p * p <= x; p++) {
                    int cnt = 0;
                    while (x % p == 0) {
                        x /= p;
                        cnt++;
                    }
                    primeExp[p] = max(primeExp[p], cnt);
                }
                if (x > 1)
                    primeExp[x] = max(primeExp[x], 1);
            }
        }

        // Build LCM modulo MOD
        long long ans = 1;
        for (auto &[p, e] : primeExp) {
            ans = (ans * modPow(p, e)) % MOD;
        }

        return (int)ans;
    }
};