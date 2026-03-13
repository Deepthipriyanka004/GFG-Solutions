class Solution {
  public:
    void solve(string s, int i, vector<string> &ans, string temp, int count) {
        if (count > 4)
            return;
        if (i == s.size()) {
            if (count == 4) {
                ans.push_back(temp);
            }
            return;
        }
        string t = "";
        int n = s.size();
        for (int ind = i; ind < min(n, i + 3); ind++) {
            t += s[ind];
            if ((t.size() > 1 && t[0] == '0') || stoi(t) > 255)
                break;
            if (!temp.empty()) {
                solve(s, ind + 1, ans, temp + "." + t, count + 1);
            } else {
                solve(s, ind + 1, ans, t, count + 1);
            }
        }
    }
    vector<string> generateIp(string &s) {
        // code here
        if(s.size()<4)
            return {"-1"};
        vector<string> ans;
        solve(s,0,ans,"",0);
        return ans;
    }
};