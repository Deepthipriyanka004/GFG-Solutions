//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int l=0,m=0,h=arr.size()-1;
        while(m<=h){
            if(arr[m]==0){
                swap(arr[l],arr[m]);
                l++;
                m++;
            }
            else if(arr[m]==1){
                m++;
            }
            else{
                swap(arr[m],arr[h]);
                h--;
            }
        }
    }
};

