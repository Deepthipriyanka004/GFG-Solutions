class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int i=0,j=height.size()-1,maxx=INT_MIN,h=0;
        while(i<j){
            if(height[i]<=height[j]){
                h=height[i];
                i++;
            }
            else{
                h=height[j];
                j--;
            }
            maxx=max(maxx,h*(j-i));
        }
        return maxx;
    }
};