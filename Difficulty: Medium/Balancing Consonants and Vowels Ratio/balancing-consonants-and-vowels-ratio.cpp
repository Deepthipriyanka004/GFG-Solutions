class Solution {
  public:
    int diff(string s){
        int v=0,c=0;
        for(auto i:s){
            if(i=='a' or i=='e' or i=='o' or i=='i' or i=='u') v++;
            else c++;
        }
        return v-c;
    }
    int countBalanced(vector<string>& arr) {
        // code here
        vector<int>v;
        for(auto it:arr){
            v.push_back(diff(it));
        }
        unordered_map<int,int>mp;
        mp[0]++;
        int ans=0;
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(mp.find(0) != mp.end()) ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};