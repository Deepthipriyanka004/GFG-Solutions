class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        vector<int>dist(V,INT_MAX);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int no=it.first;
                int dis=it.second;
                if(d+dis<dist[no])
                {
                    dist[no]=d+dis;
                    pq.push({d+dis,no});
                }
            }
        }
        if(dist[dest]==INT_MAX)
            return -1;
        return dist[dest];
    }
};