class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int l=0, cnt=0;
        unordered_map<int,int> freq;
        for(int r=0;r<arr.size();r++){
            freq[arr[r]]++;
            while(freq.size()>k){
                freq[arr[l]]--;
                if(freq[arr[l]]==0) freq.erase(arr[l]);
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
};