class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        unordered_map<char,int> mp;
        int second=0,first=0,ans=INT_MAX;
        while(second< s.length()){
            mp[s[second]]++;
            while(mp.size()==3){
                ans=min(ans,second-first+1);
                mp[s[first]]--;
                if(mp[s[first]]==0){
                    mp.erase(s[first]);
                }
                first++;
            }
            second++;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};