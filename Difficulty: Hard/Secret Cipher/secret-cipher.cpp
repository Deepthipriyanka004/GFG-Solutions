class Solution {
public:
    string compress(string &s) {
        int n = s.size();

        vector<string> dp(n + 1);
        dp[0] = "";

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + s[i - 1];

            if (i % 2 == 0) {
                int half = i / 2;

                if (s.substr(0, half) == s.substr(half, half)) {
                    string candidate = dp[half] + '*';

                    if (candidate.size() < dp[i].size()) {
                        dp[i] = candidate;
                    } else if (candidate.size() == dp[i].size() &&
                               candidate < dp[i]) {
                        dp[i] = candidate;
                    }
                }
            }
        }

        return dp[n];
    }
};