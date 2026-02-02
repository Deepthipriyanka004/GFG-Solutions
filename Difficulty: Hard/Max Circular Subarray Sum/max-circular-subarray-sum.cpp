class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int totalsum=0;
        int currmax=0,maxsum=INT_MIN;
        int currmin=0,minsum=INT_MAX;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
            currmax=max(arr[i],currmax+arr[i]);
            maxsum=max(currmax,maxsum);
            currmin=min(arr[i],currmin+arr[i]);
            minsum=min(minsum,currmin);
        }
        if(maxsum<0){
            return maxsum;
        }
        return max(maxsum,totalsum-minsum);
    }
};