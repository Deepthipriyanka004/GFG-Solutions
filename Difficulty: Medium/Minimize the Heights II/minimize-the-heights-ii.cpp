class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];
        int small = arr[0]+k;
        int large = arr[n-1]-k;
        for(int i=0;i<n-1;i++){
            int mini = min(small, arr[i+1]-k);
            int maxi = max(large, arr[i]+k);
            
            if(mini>=0){
                ans = min(ans, maxi-mini);
            }
        }
        return ans;
    }
};