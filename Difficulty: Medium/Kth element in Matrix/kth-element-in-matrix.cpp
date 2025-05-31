class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flat;
        for (auto& row : matrix)
            flat.insert(flat.end(), row.begin(), row.end());
        sort(flat.begin(), flat.end());
        return flat[k - 1];
    }
};