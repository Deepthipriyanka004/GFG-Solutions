class Solution {
  public:
    int dp[101][102][102];

    int solve(int idx, int inc, int dec, vector<int>& arr) {
        if (idx == arr.size()) return 0;

        int &res = dp[idx][inc][dec];
        if (res != -1) return res;

        res = solve(idx + 1, inc, dec, arr); // skip

        int x = arr[idx];

        if (x > inc) {
            res = max(res, 1 + solve(idx + 1, x, dec, arr));
        }

        if (x < dec) {
            res = max(res, 1 + solve(idx + 1, inc, x, arr));
        }

        return res;
    }

    int minCount(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));

        int used = solve(0, 0, 101, arr);
        return arr.size() - used;
    }
};