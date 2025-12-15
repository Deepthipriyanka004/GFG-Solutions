class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int oddSum = 0, evenSum = 0;
        for(int i=0;i<arr.size();i++){
            if(i%2)
                oddSum += arr[i];
            else
                evenSum += arr[i];
        }
        int res = 0;
        int oddSum2 = 0, evenSum2 = 0;
        for(int i=0;i<arr.size();i++){
            if(i%2){
                oddSum -= arr[i];
                if(oddSum + evenSum2 == evenSum + oddSum2)
                    res++;
                oddSum2 += arr[i];
            }
            else{
                evenSum -= arr[i];
                if(oddSum + evenSum2 == evenSum + oddSum2)
                    res++;
                evenSum2 += arr[i];
            }
        }
        return res;
    }
};