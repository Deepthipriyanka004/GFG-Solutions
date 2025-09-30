class Solution {
  public:
    void getAns(string &str,vector<string> &ans,int index){
        if(index>=str.size()){
          ans.push_back(str);
          return;
        }
        str[index]='0';
        getAns(str,ans,index+1);
        str[index]='1';
        getAns(str,ans,index+1);
    }
    vector<string> binstr(int n) {
        // code here
        string str(n,'0');
        vector<string> ans;
        int  index=0;
        getAns(str,ans,index);
        return ans;
    }
};