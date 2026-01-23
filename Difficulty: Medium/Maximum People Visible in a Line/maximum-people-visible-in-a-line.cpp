class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        int res=1;
        vector<int> maxarr={-1};
        int maxi = *max_element(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]==maxi)
                maxarr.push_back(i);
        }
        maxarr.push_back(n);
        for(int i=0;i<maxarr.size()-1;i++)
            res=max(res,maxarr[i+1]-maxarr[i-1]-1);
        return res;
    }
};