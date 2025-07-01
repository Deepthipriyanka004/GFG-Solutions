class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        vector<int> cnt(26);
        int ans = 0, d = 0, n = s.length();
        for (int i = 0; i < k - 1; i++) if (++cnt[s[i]-'a'] == 1) d++;
        for (int i = k - 1; i < n; i++) {
            if (++cnt[s[i]-'a'] == 1) d++;
            if (d == k - 1) ans++;
            if (--cnt[s[i-k+1]-'a'] == 0) d--;
        }
        return ans;
    }
};