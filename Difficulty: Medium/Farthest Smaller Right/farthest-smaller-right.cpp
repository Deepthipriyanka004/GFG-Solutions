class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        vector<int> suff(n);
        suff[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i] = min(arr[i],suff[i+1]);
        }
        for(int i = 0;i<n;i++){
            int s = i+1,e = n-1;
            int found = -1;
            while(s<=e){
                int mid = (s+e)/2;
                if(arr[i]>suff[mid]){
                    found = mid;
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
            ans[i] = found;
        }
        return ans;
    }
};