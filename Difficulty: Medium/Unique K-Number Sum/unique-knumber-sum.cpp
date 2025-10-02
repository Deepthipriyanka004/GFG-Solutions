class Solution {
  public:
    void dfs(int n, int k, int start, vector<int> &curr, vector<vector<int>> &ans) {
        if (n == 0 && k == 0) {
            ans.push_back(curr);
            return;
        }
        if (n <= 0 || k <= 0) return;
        for (int i = start; i <= 9; ++i) {
            if (i > n) 
              break;             
            curr.push_back(i);
            dfs(n - i, k - 1, i + 1, curr, ans); 
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(n, k, 1, curr, ans);
        return ans;
    }
};