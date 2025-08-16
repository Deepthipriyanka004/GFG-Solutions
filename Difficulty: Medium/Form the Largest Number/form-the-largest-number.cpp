class Solution {
  public:
    static bool cmp(int & i, int & j){
        return to_string(i)+to_string(j) > to_string(j)+to_string(i);
    }
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end(), cmp);
        string res = "";
        for(auto it : arr)
        res += to_string(it);
        return res[0]=='0' ? "0" : res;
    }
};