class Solution {
	public:
	string findLongestWord(string &S, vector<string> &d) {
		// code here
		int n = S.size();
		vector<vector<int>> next(n + 1, vector<int>(26, -1));
		for (int c = 0; c < 26; c++)
			next[n][c] = -1;
		for (int i = n - 1; i >= 0; i--) {
			next[i] = next[i + 1];
			next[i][S[i] - 'a'] = i;
		}
		string ans = "";
		for (string &word : d) {
			int pos = 0;
			bool ok = true;
			for (char ch : word) {
				if (pos > n || next[pos][ch - 'a'] == -1) {
					ok = false;
					break;
				}
				pos = next[pos][ch - 'a'] + 1;
			}
			if (ok) {
				if (word.size() > ans.size() ||
				(word.size() == ans.size() && word < ans))
				ans = word;
			}
		}
		return ans;
	}
};