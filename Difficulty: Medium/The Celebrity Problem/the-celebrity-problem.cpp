class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int high = n-1, low = 0;
        while(high > low){
            if(mat[high][low] == 0 && mat[low][high] == 1) low++;
            else if(mat[low][high] == 0 && mat[high][low] == 1) high--;
            else low++, high--;
        }
        if(low != high) return -1;
        // Checking if candidate is really a celebrity
        for(int i = 0; i < m; i++){
            if(i == high) continue;
            if(mat[high][i] == 1) return -1;
        }
        for(int i = 0; i < n; i++){
            if(i == high) continue;
            if(mat[i][high] == 0) return -1;
        }
        return high;
    }
};