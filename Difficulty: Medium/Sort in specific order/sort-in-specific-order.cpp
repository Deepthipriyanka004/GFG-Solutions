class Solution {
  public:
    static bool cmp(int a , int b){
        if((a & 1) == 1 && (b & 1) == 1)
            return a > b;
        else if((a & 1) == 0 && (b & 1) == 0)
            return a < b;
        else
            return ((a & 1) > (b & 1));
    }
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),cmp);
    }
};