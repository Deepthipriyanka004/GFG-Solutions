class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> Subqcnt(n, 1);
        vector<int> Subqsum(n);
        int Maxlen = 1;
        int TotalSum = 0;
        int LISSum = INT_MAX;
        
        for(int i = 0;i<n;i++){
            TotalSum += arr[i];
            Subqsum[i] = arr[i];
            for(int j = 0;j<i;j++){
                if(arr[i]>arr[j] and (Subqcnt[j]+1)>=Subqcnt[i]){
                    Subqcnt[i] = Subqcnt[j] + 1;
                    Subqsum[i] = Subqsum[j] + arr[i];
                }
            }
            if(Maxlen < Subqcnt[i]){
                Maxlen = Subqcnt[i];
            }
        }
        
        for(int i = 0;i<n;i++){
            if(Maxlen == Subqcnt[i]){
                LISSum = min(LISSum, Subqsum[i]);
            }
        }
         
        return TotalSum - LISSum;
    }
};