class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int N = a.size();
        int M = b.size();

        unordered_map<int, int> pos;
        for (int i = 0; i < M; i++) {
            pos[b[i]] = i + 1;
        }

        vector<int> lis;

        for (int i = 0; i < N; i++) {
            if (pos.find(a[i]) != pos.end()) {
                int idx = pos[a[i]];

                auto it = lower_bound(lis.begin(), lis.end(), idx);
                if (it == lis.end())
                    lis.push_back(idx);
                else
                    *it = idx;
            }
        }

        int lcs = lis.size();

        int deletions = N - lcs;
        int insertions = M - lcs;

        return deletions + insertions;
    }
};