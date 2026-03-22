class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;
        
        // Step 1: Add all rotten oranges to queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({{i,j}, 0});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int time = 0;
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        
        // Step 2: BFS
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = max(time, t);
            
            for(int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                
                // Check bounds + fresh orange
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                    mat[nr][nc] = 2; // make rotten
                    q.push({{nr, nc}, t + 1});
                    fresh--;
                }
            }
        }
        
        // Step 3: Check if all oranges rotten
        if(fresh > 0) return -1;
        
        return time;
    }
};