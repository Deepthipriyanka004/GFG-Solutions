class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        vector<int> pre(n);
        pre[0] = s[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + s[i];
        }
        unordered_map<char,pair<int,int>>mp;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(mp.find(ch)==mp.end()){
                mp[ch].first= i;
                mp[ch].second = -1;
            }else{
                mp[ch].second = i;
            }
        }
        vector<int> ans;
        for(auto& it : mp){
            int s = it.second.first;
            int e = it.second.second;
            if(e == -1) continue;
            int t = pre[e-1]-pre[s];
            if(t==0) continue;
            ans.push_back(t);
        }
        return ans;
    }
};