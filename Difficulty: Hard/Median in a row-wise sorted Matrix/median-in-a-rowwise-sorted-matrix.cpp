class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>mt;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                mt.push_back(mat[i][j]);
            }
        }
        sort(mt.begin() , mt.end());
        return mt[mt.size() / 2];
    }
};