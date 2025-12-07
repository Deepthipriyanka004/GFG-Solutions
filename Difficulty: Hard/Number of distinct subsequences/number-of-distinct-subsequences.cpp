class Solution {
public:
    int distinctSubseq(string& str) {
        int n = str.size(), mod = 1e9 + 7, res = 1;
        vector<int> last(26);
        for (int i = 0; i < n; i++) {
            int idx = str[i] - 'a';
            int cur = (2LL * res % mod - last[idx] + mod) % mod;
            last[idx] = res;
            res = cur;
        }
        return res;
    }
};