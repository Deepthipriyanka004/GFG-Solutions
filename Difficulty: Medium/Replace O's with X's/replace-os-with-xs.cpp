class Solution {
  public:
    int r,c;
    void dfs(vector<vector<char>>& mat,int i,int j){
        if(i<0 || i>=r || j<0 || j>=c || mat[i][j]=='X' || mat[i][j]=='T')return;
        mat[i][j]='T';
        dfs(mat,i-1,j);
        dfs(mat,i+1,j);
        dfs(mat,i,j-1);
        dfs(mat,i,j+1);
    }
    void modifiedDfs(vector<vector<char>>& mat,int i,int j,char symbol){
        if(i<0 || i>=r || j<0 || j>=c || mat[i][j]=='O' || mat[i][j]=='X')return;
        mat[i][j]=symbol;
        modifiedDfs(mat,i-1,j,symbol);
        modifiedDfs(mat,i+1,j,symbol);
        modifiedDfs(mat,i,j-1,symbol);
        modifiedDfs(mat,i,j+1,symbol);
    }
    void fill(vector<vector<char>>& mat) {
        // Code here
        r = mat.size();
        c = mat[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='O')dfs(mat,i,j);
            }
        }
        
        
        for(int i=0;i<c;i++){
            if(mat[0][i]=='T')modifiedDfs(mat,0,i,'O');
            
            if(mat[r-1][i]=='T')modifiedDfs(mat,r-1,i,'O');
        }
        
        for(int i=0;i<r;i++){
            if(mat[i][0]=='T' )modifiedDfs(mat,i,0,'O');
            if(mat[i][c-1]=='T')modifiedDfs(mat,i,c-1,'O');
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='T')modifiedDfs(mat,i,j,'X');
            }
        }
    }
};