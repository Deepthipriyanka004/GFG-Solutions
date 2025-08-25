class Solution {
  public:
    int med(vector<int> & arr){
        int n = arr.size();
        if(n&1){
            int ele = arr[n/2];
            return ele;
        }
        else{
            int p = (arr[n/2] + arr[(n/2)-1])/2;
            return p;
        }
        return 0;
    }
    bool f(int mid , int  k, vector<int> arr ){
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
            if(k==0)break;
            if(arr[i]<mid){
                int dif = mid - arr[i];
                if(k>=dif){
                    arr[i]+=dif;
                    k-=dif;
                }
                else{
                    arr[i]+=k;
                    k=0;
                }
            }
        }
        return (med(arr)>=mid) ;
    }
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int lo =  0 , hi = 1e9,ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(f(mid,k,arr)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
       }
       return ans;
    }
};