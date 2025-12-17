class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i = 1;i<n;i++){
            vector<int> x = ans.back();
            ans.pop_back();
            if(x[1]>= arr[i][0]){
                ans.push_back({x[0],max(arr[i][1],x[1])});
            }
            else{
                ans.push_back(x);
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};