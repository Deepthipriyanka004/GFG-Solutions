class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto q : queries){
            int l = q[0], r = q[1];
            int i1 = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
            int i2 = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
            ans.push_back(i2 - i1);
        }
        return ans;
    }
};