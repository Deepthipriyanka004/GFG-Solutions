class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        sort(a.begin(),a.end());
        int minDif=1e9;
        for(int i=0;i<=n-m;i++){
            minDif=min(minDif,a[i+m-1]-a[i]);
        }
        return minDif;
    }
};