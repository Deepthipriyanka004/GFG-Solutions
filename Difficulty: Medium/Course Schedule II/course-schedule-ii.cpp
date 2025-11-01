class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i = 0;i<indegree.size();i++){
            if(!indegree[i])q.push(i);
        }
        vector<int>ans;
        while(q.size()){
            auto elem = q.front();
            q.pop();
            ans.push_back(elem);
            for(auto it : adj[elem]){
                indegree[it]--;
                if(!indegree[it])q.push(it);
            }
        }
        return ans;
    }
};