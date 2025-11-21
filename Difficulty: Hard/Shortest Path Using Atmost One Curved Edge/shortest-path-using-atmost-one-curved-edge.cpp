class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // adjacency list: for each node store {neighbor, straightWeight, curvedWeight}
        vector<vector<array<int,3>>> adj(V);
        for (auto &e : edges) {
            int x = e[0], y = e[1], w1 = e[2], w2 = e[3];
            adj[x].push_back({y, w1, w2});
            adj[y].push_back({x, w1, w2});
        }

        // dist[node][usedCurved] : 2 states per node
        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));
        dist[a][0] = 0;

        // min-heap: {distance, node, usedCurved}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        pq.push({0, a, 0});

        while (!pq.empty()) {
            auto [d, u, used] = pq.top();
            pq.pop();

            if (d != dist[u][used]) continue;

            for (auto &nx : adj[u]) {
                int v = nx[0], w1 = nx[1], w2 = nx[2];

                // use straight edge
                if (d + w1 < dist[v][used]) {
                    dist[v][used] = d + w1;
                    pq.push({dist[v][used], v, used});
                }

                // use curved edge only if not used yet
                if (used == 0) {
                    if (d + w2 < dist[v][1]) {
                        dist[v][1] = d + w2;
                        pq.push({dist[v][1], v, 1});
                    }
                }
            }
        }

        int ans = min(dist[b][0], dist[b][1]);
        return (ans == INT_MAX ? -1 : ans);
    }
};
