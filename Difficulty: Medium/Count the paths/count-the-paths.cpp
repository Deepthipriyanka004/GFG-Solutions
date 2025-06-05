class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> graph(V);
        vector<int> ind(V),paths(V);
        for(auto& e:edges){
            graph[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }
        vector<bool> inPath(V,false);
        queue<int> qu;
        for(int i=0;i<V;i++){
            if(ind[i]==0){
                qu.push(i);
                if(i==src) inPath[i]=true,paths[i]=1;
            }
        }
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            // cout<<u<<" "<<paths[u]<<" "<<inPath[u]<<"\n";
            for(int& v:graph[u]){
                ind[v]--;
                if(inPath[u]) paths[v]+=paths[u],inPath[v]=true;
                if(ind[v]==0) qu.push(v);
                if(v==src) inPath[v]=true,paths[v]=1;
            }
        }
        return paths[dest];
    }
};