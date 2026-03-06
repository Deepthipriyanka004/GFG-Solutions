class Solution {
  public:
    string minWindow(string &s, string &t) {
        // code here
        int n = s.size();
        int m = t.size();
        int start = -1;
        int cnt = 0;
        int l=0,r=0,mini=1e9;
        map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        while(r<n){
            if(mp[s[r]]>0){
                cnt++;
            }
            mp[s[r]]--;
            while(cnt==m){
                // shrink while possible
                if(r-l+1<mini){
                    mini = r-l+1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(start==-1)return"";
        return s.substr(start,mini);
    }
};