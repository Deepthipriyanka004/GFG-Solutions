class Solution {
  public:
  
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }
  
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(V, 0);
        int candidate = -1;
        
        // Find possible mother vertex
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                candidate = i;
            }
        }
        
        // Verify candidate
        fill(vis.begin(), vis.end(), 0);
        dfs(candidate, adj, vis);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) return -1;
        }
        
        // To get smallest mother vertex
        for (int i = 0; i < candidate; i++) {
            fill(vis.begin(), vis.end(), 0);
            dfs(i, adj, vis);
            
            bool ok = true;
            for (int j = 0; j < V; j++) {
                if (!vis[j]) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) return i;
        }
        
        return candidate;
    }
};