class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string> ans;
        for(int mask=0;mask<(1<<n);mask++){
            int g = mask ^ (mask >> 1);
            string s="";
            for(int i=n-1;i>=0;i--){
                if(g&(1<<i)) s+='1';
                else s+='0';
            }
            ans.push_back(s);
        }
        return ans;
    }
};