class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>> result;
        int idx = 0, levelSize = 1, n = arr.size();
        while (idx < n) {
            vector<int> temp;
            // collect current level values
            for (int i = idx; i < idx + levelSize && i < n; i++) {
                temp.push_back(arr[i]);
            }
            sort(temp.begin(), temp.end());
            result.push_back(temp);
            idx += levelSize;   // move to next level
            levelSize *= 2;     // next level has double nodes
        }
        return result;
    }
};