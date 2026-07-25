class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int ans=INT_MIN,n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>=1){
                    mat[i][j]+=mat[i-1][j];
                }
                if(j>=1){
                    mat[i][j]+=mat[i][j-1];
                }
                if(i>=1 && j>=1){
                    mat[i][j]-=mat[i-1][j-1];
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=mat[i][j];
                if(i>=k){
                    sum-=mat[i-k][j];
                }
                if(j>=k){
                    sum-=mat[i][j-k];
                }
                if(i>=k && j>=k){
                    sum+=mat[i-k][j-k];
               
                }
                if(i>=k-1 && j>=k-1){
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};