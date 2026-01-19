class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string ans="";
        for(char &c:s){
            while(ans.size() and ans.back()>c and k){
                ans.pop_back();
                k--;
            }
            if(ans.size() or c!='0'){
                ans.push_back(c);
            }
        }
        while(ans.size() and k--){
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
    }
};