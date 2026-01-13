class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int f=0,t=0;
        for(int &i:arr){
            if(i==5) ++f;
            else if(i==10){
                --f;++t;
            }
            else{
                if(f>0 && t>0) {--f;--t;}
                else f-=3;   
            }
            if(f<0 || t<0) return false;
        }
        return true;
    }
};