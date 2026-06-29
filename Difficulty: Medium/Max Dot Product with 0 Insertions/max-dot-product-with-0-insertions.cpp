class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(),m=b.size();
        if(n<m){
            return 0;
        }
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>i){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i-1]*b[j-1]);
                }
            }
        }
        return dp[n][m];
    }
};