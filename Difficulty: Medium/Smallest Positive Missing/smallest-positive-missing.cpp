class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int count=1,n=arr.size();
        sort(arr.begin(),arr.end());
        for (int i=0;i<n;i++){
            if (arr[i]==count)
            count++;
        }
        return count;
    }
};
