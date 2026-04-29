class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalOne=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                totalOne++;
            }
        }
        if(totalOne==0){
            return -1;
        }
        int i=0;
        int zero=0,one=0;
        for(i=0;i<totalOne;i++){
            if(arr[i]==0){
                zero++;
            }
            else{
                one++;
            }
        }
        int ans = (totalOne-one);
        int prev=0;
        for(;i<n;i++){
            if(arr[prev]==0){
                zero--;
            }
            else{
                one--;
            }
            if(arr[i]==0){
                zero++;
            }
            else{
                one++;
            }
            prev++;
            ans = min(ans,totalOne-one);
        }
        return ans;
    }
};