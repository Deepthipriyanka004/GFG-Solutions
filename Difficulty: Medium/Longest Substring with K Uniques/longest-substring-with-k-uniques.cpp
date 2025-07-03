class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.size(), ans = -1;
        while (r<n){
            mp[s[r]]++;
            while (mp.size()>k){
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k) ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};