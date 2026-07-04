class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;
        int n;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
    };

    int countSubstring(string& s) {
        int n = s.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        long long ans = 0;

        for (int x : prefix) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller than current
            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return (int)ans;
    }
};