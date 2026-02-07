class Solution {
  public:
    long long maxSum(vector<int>& a) {
        int n = a.size();
        long long sum = 0, tsum = 0;

        for(int i = 0; i < n; i++){
            sum += a[i];
            tsum += (long long)i * a[i];
        }

        long long maxi = tsum;

        for(int i = 1; i < n; i++){
            tsum = tsum + sum - (long long)n * a[n - i];
            maxi = max(maxi, tsum);
        }

        return maxi;
    }
};
