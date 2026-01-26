class Solution {
  public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr,int i){
        if(i>=arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int j=i;j<arr.size();j++){
            swap(arr[i],arr[j]);
            solve(arr,i+1);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        solve(arr,0);
        return ans;
    }
};