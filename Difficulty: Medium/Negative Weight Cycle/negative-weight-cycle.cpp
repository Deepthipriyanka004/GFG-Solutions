class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<long long> dist(V, 0);

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative cycle
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (dist[u] + w < dist[v]) {
                return true;
            }
        }

        return false;
    }
};