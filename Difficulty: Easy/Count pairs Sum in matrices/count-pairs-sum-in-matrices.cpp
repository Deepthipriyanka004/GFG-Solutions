class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        int r1 = 0, c1 = 0, r2 = b.size() - 1, c2 = b[0].size() - 1, cnt = 0;
        while (r1 < a.size() && r2 >= 0) {
            int sum = a[r1][c1] + b[r2][c2];
            if (sum == x) ++cnt, ++c1, --c2;
            else if (sum < x) ++c1;
            else --c2;
            if (c1 == a[0].size()) c1 = 0, ++r1;
            if (c2 < 0) c2 = b[0].size() - 1, --r2;
        }
        return cnt;
    }
};