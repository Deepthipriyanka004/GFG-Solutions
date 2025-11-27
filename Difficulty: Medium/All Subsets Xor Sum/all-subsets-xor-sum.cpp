class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;

        for(int bit = 0; bit < 11; bit++) {
            int countSet = 0;
            for(int num : arr) {
                if(num & (1 << bit)) countSet++;
            }
            if(countSet > 0) {
                ans += (1 << bit) * (1 << (n - 1));
            }
        }

        return ans;
    }
};