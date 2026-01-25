class Solution {
  public:
    int nthCatalan(int n){
        vector<int>t(n+1);
        t[0]=t[1]=1;
        for(int i=2;i<t.size();i++){
            for(int j=0;j<i;j++){
                t[i]+=t[j]*t[i-j-1];
            }
        }
        return t[n];
    }
    int findWays(int n) {
        // code here
        if(n%2==1)return 0;
        return nthCatalan(n/2);
    }
};