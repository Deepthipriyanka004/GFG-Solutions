class Solution {
  public:
    int solve(int n) {
        return (n * (n - 1)) / 2;
    }
    int countIncreasing(vector<int>& arr) {
        // code here.
        int res = 0;
        int i = 0, j = 1;
        int n = arr.size();
        while (i < n) {
            while (j < n && arr[j] > arr[j - 1]){
                j++;
            }
            res += solve(j - i);
            i = j;
            j++;
        }
        return res;
    }
};