class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j = 0;  // position for next non-zero
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};