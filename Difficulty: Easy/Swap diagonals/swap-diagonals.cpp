class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),i=0,j=n-1;
        for(;i<n;i++){
            swap(mat[i][i],mat[i][j--]);
        }
    }
};