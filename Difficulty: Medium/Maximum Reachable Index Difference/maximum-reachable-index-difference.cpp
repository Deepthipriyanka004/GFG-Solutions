class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();
        vector<int> bestEnd(26, -1);
        int ans = -1;
        bool hasA = false;
        for (int i = n - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (c == 0) hasA = true;
            int end = i;
            if (c < 25 && bestEnd[c + 1] != -1) {
                end = max(end, bestEnd[c + 1]);
            }
            bestEnd[c] = max(bestEnd[c], end);
            if (c == 0) {
                ans = max(ans, end - i);
            }
        }
        return hasA ? ans : -1;
    }
};