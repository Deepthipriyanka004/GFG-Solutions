class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0,j = 0;
        int count = 0;
        int ans = 0;
        while(i<n && j<n){
            if(arr[j] == 0)
            count ++;
            while(count>k){
                if(arr[i] == 0)
                count--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};