class Solution {
  public:
    int solve(int n,int m,int last,int count,vector<vector<int>>&dp){
        if(count==n){
            return 1;
        }
        if(dp[last][count]!=-1){
            return dp[last][count];
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(last%i==0 || i%last==0){
                ans+=solve(n,m,i,count+1,dp);
            }
        }
        return dp[last][count]=ans;
    }
    int count(int n, int m) {
        // code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(n,m,1,0,dp);
    }
};