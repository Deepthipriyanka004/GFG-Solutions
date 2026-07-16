class Solution {
  public:
    int countWays(int n, int sum) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                for(int k=0;k<=9;k++){
                    if(j>=k){
                        dp[i][j]+=dp[i-1][j-k];
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=9;i++){
            if(sum>=i)ans+=dp[n-1][sum-i];
        }
        return (ans == 0)?-1:ans;
    }
};