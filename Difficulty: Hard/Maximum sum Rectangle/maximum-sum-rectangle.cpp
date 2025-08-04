class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;
        // Left and right boundaries of the submatrix
        for (int left = 0; left < m; ++left) {
            vector<int> temp(n, 0);
            for (int right = left; right < m; ++right) {
                // Add current column to temp array (collapsing to 1D)
                for (int i = 0; i < n; ++i)
                    temp[i] += mat[i][right];
                // Apply Kadane's algorithm to temp[]
                int currentSum = temp[0];
                int maxCurrent = temp[0];
                for (int i = 1; i < n; ++i) {
                    currentSum = max(temp[i], currentSum + temp[i]);
                    maxCurrent = max(maxCurrent, currentSum);
                }
                // Update global max sum
                maxSum = max(maxSum, maxCurrent);
            }
        }
        return maxSum;
    }
};