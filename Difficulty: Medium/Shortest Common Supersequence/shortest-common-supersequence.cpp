class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> lcs(n+1, vector<int>(m+1));
        for (int i=0; i<=n; i++) lcs[i][0] = 0;
        for (int i=0; i<=m; i++) lcs[0][i] = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        int longestCommon = lcs[n][m];
        return (n+m-longestCommon);
    }
};