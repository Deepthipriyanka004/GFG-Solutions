class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        if(n <= 1) return true;
        
        // Sort by start time only
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        int prevEnd = arr[0][1];
        
        for(int i = 1; i < n; i++) {
            if(arr[i][0] < prevEnd) {
                return false;
            }
            prevEnd = arr[i][1];
        }
        
        return true;
    }
};
