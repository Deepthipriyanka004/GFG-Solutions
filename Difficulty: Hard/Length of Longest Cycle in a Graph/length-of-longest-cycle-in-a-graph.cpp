class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> next(V, -1);
        for (auto &e : edges) {
            next[e[0]] = e[1];
        }
        
        vector<int> visited(V, 0);
        int ans = -1;
        
        for (int i = 0; i < V; i++) {
            
            if (visited[i]) continue;
            
            unordered_map<int, int> timeVisited;
            int node = i;
            int time = 0;
            
            while (node != -1) {
                
                if (visited[node]) break;
                
                visited[node] = 1;
                timeVisited[node] = time++;
                
                node = next[node];
                
                // Cycle detected
                if (node != -1 && timeVisited.find(node) != timeVisited.end()) {
                    int cycleLength = time - timeVisited[node];
                    ans = max(ans, cycleLength);
                    break;
                }
            }
        }
        
        return ans;
    }
};