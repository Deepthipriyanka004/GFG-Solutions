class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        sort(discs.begin(), discs.end());

        // dp[x] = maximum stack height whose top disc has height x
        vector<int> dp(1001, 0);

        int ans = 0;

        int i = 0;

        while (i < n) {
            int j = i;

            // Same radius group
            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            vector<pair<int, int>> updates;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int best = 0;

                for (int x = 1; x < height; x++) {
                    best = max(best, dp[x]);
                }

                int current = best + height;

                updates.push_back({height, current});
                ans = max(ans, current);
            }

            // Update only after processing the whole radius group
            for (auto &p : updates) {
                dp[p.first] = max(dp[p.first], p.second);
            }

            i = j;
        }

        return ans;
    }
};