class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans=0;
        for(int i=n-1;i>1;i--){
            int l=0, r=i-1;
            while(r>l){
                if((arr[l]+arr[r]) > arr[i]){
                    ans += (r-l);
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};