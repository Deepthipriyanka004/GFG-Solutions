class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int xorVal = 0;
        int maxXor = INT_MIN;
        int i=0;
        int j=0;
        while(j<arr.size()){
            xorVal ^= arr[j];
            if(j-i+1 == k){
                maxXor = max(maxXor,xorVal);  
                xorVal ^=  arr[i];
                i++;
            }
            j++;
        }
        return maxXor;
    }
};