class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> rpre(r+1, vector<int>(c+1,0));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                rpre[i+1][j+1] = rpre[i][j+1] + rpre[i+1][j] - rpre[i][j] + mat[i][j];
        vector<int> res;
        for(auto it : queries){
            int tlr = it[0];
            int tlc = it[1];
            int brr = it[2];
            int brc = it[3];
            int temp = rpre[brr+1][brc+1] - rpre[tlr][brc+1] - rpre[brr+1][tlc] + rpre[tlr][tlc];
            res.push_back(temp);
        }
        return res;
    }
};