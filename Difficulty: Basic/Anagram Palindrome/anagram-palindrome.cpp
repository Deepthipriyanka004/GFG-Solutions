class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char, int>mpp;
        for(auto it : s)mpp[it]++;
        int odd = 0;
        for(auto it : mpp){
            if(it.second & 1){
                if(odd)return false;
                odd++;
                continue;
            }
        }
        return true;
    }
};