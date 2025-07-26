class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int>res;
        map<int,int>mp;
        for(int i = 0;i < arr.size();i++) mp[arr[i]]++;
        for(auto x:mp){
            if(x.second > arr.size() / 3) res.push_back(x.first);
        }
        return res;
    }
};