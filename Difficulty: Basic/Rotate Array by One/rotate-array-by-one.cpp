class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n=arr.size();
        arr.insert(arr.begin(),arr[n-1]);
        arr.pop_back();
    
        
    }
};