class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        // Create difference array with extra padding
        vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));
        
        // Initialize difference array with original matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diff[i][j] = mat[i][j];
                if(i > 0) diff[i][j] -= mat[i-1][j];
                if(j > 0) diff[i][j] -= mat[i][j-1];
                if(i > 0 && j > 0) diff[i][j] += mat[i-1][j-1];
            }
        }
        
        // Apply all operations on difference array
        for(auto& op : opr) {
            int v = op[0];
            int r1 = op[1];
            int c1 = op[2];
            int r2 = op[3];
            int c2 = op[4];
            
            // Update difference array for range [r1,c1] to [r2,c2]
            diff[r1][c1] += v;
            if(r2 + 1 < n) diff[r2 + 1][c1] -= v;
            if(c2 + 1 < m) diff[r1][c2 + 1] -= v;
            if(r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }
        
        // Compute final matrix using 2D prefix sum
        vector<vector<int>> result(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = diff[i][j];
                if(i > 0) result[i][j] += result[i-1][j];
                if(j > 0) result[i][j] += result[i][j-1];
                if(i > 0 && j > 0) result[i][j] -= result[i-1][j-1];
            }
        }
        
        return result;
    }
};