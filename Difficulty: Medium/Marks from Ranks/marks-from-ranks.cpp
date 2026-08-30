class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size();
        vector<long long> prefix(n);
        for (int i = 0; i < n; i++) {
            long long count = 1LL * r[i] - l[i] + 1;
            prefix[i] = count + (i > 0 ? prefix[i - 1] : 0);
        }
        vector<int> answer;
        answer.reserve(rank.size());
        for (int currentRank : rank) {
            int index = lower_bound(prefix.begin(), prefix.end(), currentRank) - prefix.begin();
            long long marksBefore = (index > 0 ? prefix[index - 1] : 0);
            long long offset = currentRank - marksBefore - 1;
            answer.push_back(l[index] + offset);
        }
        return answer;
    }
};