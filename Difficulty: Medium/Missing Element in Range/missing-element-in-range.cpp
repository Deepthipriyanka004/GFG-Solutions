class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        sort(arr.begin(), arr.end());
        int si=lower_bound(arr.begin(), arr.end(), low)-arr.begin();
        int ei=lower_bound(arr.begin(), arr.end(), high)-arr.begin();
        int n=arr.size();
        unordered_map<int, bool> visited; 
        while(si<=ei){
            if(si==n) break;
            visited[arr[si]]=true;
            si++;
        }
        vector<int> ans;
        for(int i=low; i<=high; i++){
            if(!visited[i]) ans.push_back(i);  
        }
        return ans;
    }
};