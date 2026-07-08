class Solution {
  public:
    vector<vector<int>> bfs(vector<vector<int>> &heights,int type,vector<vector<int>> &used){
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(type==0 && (i==0 || j==0)){
                    q.push({i,j});
                    used[i][j]=1;
                }
                if(type==1 && (i==n-1 || j==m-1)){
                    q.push({i,j});
                    used[i][j]=1;
                }
            }
        }
        vector<int> row={1,0,0,-1};
        vector<int> col={0,1,-1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !used[nr][nc] && heights[r][c]<=heights[nr][nc]){
                    used[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return used;
    }
    int countCoordinates(vector<vector<int>>& heights) {
        // code here
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> usedp(n,vector<int>(m));
        bfs(heights,0,usedp);
        vector<vector<int>> useda(n,vector<int>(m));
        bfs(heights,1,useda);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(usedp[i][j] && useda[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};