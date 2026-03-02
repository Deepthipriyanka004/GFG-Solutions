class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> leftMaxBlock(n);
        leftMaxBlock[0]=arr[0];
        for(int i=1;i<n;i++){
           leftMaxBlock[i]=max(leftMaxBlock[i-1],arr[i]);
        }
        vector<int> rightMaxBlock(n);
        rightMaxBlock[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMaxBlock[i]=max(rightMaxBlock[i+1],arr[i]);
        }
        int maximumTrappedWater=0;
        for(int i=0;i<n;i++){
            int currentTrappedWater=min(leftMaxBlock[i],rightMaxBlock[i])-arr[i];
            maximumTrappedWater+=currentTrappedWater;
        }
        return maximumTrappedWater;
    }
};