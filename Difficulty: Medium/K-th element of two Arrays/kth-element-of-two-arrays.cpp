class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            ans.push_back(a[i]);
        }
        for(int i=0;i<b.size();i++){
            ans.push_back(b[i]);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};