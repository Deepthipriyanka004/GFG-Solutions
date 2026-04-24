class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int c=0,maxx=arr[0];
        for(auto it:arr){
            if(maxx<=it){
                c++;
            }
            maxx=max(maxx,it);
        }
        return c;
    }
};