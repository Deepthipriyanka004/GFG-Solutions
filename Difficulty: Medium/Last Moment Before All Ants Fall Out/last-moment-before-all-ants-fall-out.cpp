class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxLeft=0;
        if(left.size())
            maxLeft=*max_element(left.begin(),left.end());
        int minRight=n;
        if(right.size())
            minRight=*min_element(right.begin(),right.end());
        int ans=max(maxLeft,n-minRight);
        return ans;
    }
};