class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        
        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];
            
            
            int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            
            int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
            
            
            int count = max(0, min(right, r + 1) - max(left, l));
            ans.push_back(count);
        }
        return ans;
    }
};
