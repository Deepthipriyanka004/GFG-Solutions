class Solution {
  public:
    int BinarySearch(vector<int> &arr, int k){
        int l = 0;
        int r = arr.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(arr[m] == k){
                return m;
            }
            if(arr[m] < k){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return l;
    }
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        return BinarySearch(arr, k);
    }
};