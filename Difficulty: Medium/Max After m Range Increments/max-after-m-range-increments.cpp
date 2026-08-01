class Solution {
public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        vector<long long> diff(n + 1, 0);

        int m = a.size();

        for (int i = 0; i < m; i++) {
            diff[a[i]] += k[i];
            if (b[i] + 1 < n)
                diff[b[i] + 1] -= k[i];
        }

        long long cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            ans = max(ans, cur);
        }

        return (int)ans;
    }
};