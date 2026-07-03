class Solution {
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        // Prefix LCS
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    pref[i][j] = pref[i - 1][j - 1] + 1;
                else
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
            }
        }

        int L = pref[n][m];

        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));

        // Suffix LCS
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    suff[i][j] = suff[i + 1][j + 1] + 1;
                else
                    suff[i][j] = max(suff[i + 1][j], suff[i][j + 1]);
            }
        }

        int ans = 0;

        // Try every insertion position
        for (int pos = 0; pos <= n; pos++) {

            vector<bool> used(26, false);

            for (int j = 0; j < m; j++) {

                char c = s2[j];

                if (used[c - 'a'])
                    continue;

                if (pref[pos][j] + 1 + suff[pos][j + 1] == L + 1) {
                    ans++;
                    used[c - 'a'] = true;
                }
            }
        }

        return ans;
    }
};