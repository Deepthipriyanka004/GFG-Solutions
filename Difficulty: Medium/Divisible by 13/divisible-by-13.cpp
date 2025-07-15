class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int n=s.size();
        int i=0;
        int current=0;
        int k=13;
        while(i<n){
            while(i<n && current<k){
                current=current*10+(s[i]-'0');
                i++;
            }
            current=current%k;
        }
        if(current==0) return true;
        else return false;
    }
};