class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        set<int> s(a.begin(),a.end());
        set<int> ss(b.begin(),b.end());
        map<int,int> m;
        for(int it:s)
            m[it]++;
        for(int it:ss)
            m[it]++;
        vector<int> ans;
        for(auto it:m){
            if(it.second==2)
            ans.push_back(it.first);
        }
        return ans;
    }
};