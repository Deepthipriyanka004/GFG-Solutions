class Solution {
  public:
    bool isPossible(vector<int> arr, int k, int w, int minHeight){
        int n = arr.size();
        unordered_map<int, int> mp{};
        int curWt = 0;
        for(int i = 0; i < n && k >= 0; i++){
            if(mp.count(i)){
                curWt += mp[i];
            }
            int curHt = arr[i] + curWt;
            if(curHt >= minHeight) continue;
            if(minHeight - curHt > k) return false;
            curWt += (minHeight-curHt);
            k -= (minHeight-curHt);
            mp[i+w] -= (minHeight-curHt);
        }
        return true;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int n = arr.size();
        int minHeight = INT_MAX;
        int maxHeight = INT_MIN;
        for(int i = 0; i < n; i++){
            minHeight = min(minHeight, arr[i]);
            maxHeight = max(maxHeight, arr[i]);
        }
        int l = minHeight;
        int h = maxHeight + k;
        int res = l;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(isPossible(arr, k, w, mid)){
                res = max(res, mid);
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return res;
    }
};