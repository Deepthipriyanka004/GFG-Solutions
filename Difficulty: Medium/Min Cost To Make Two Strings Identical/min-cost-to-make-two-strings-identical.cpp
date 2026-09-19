//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int check(int ind1,int ind2,string &x,string &y,int costX,int costY){
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(ind1==x.size()){
            return (y.size()-ind2)*costY;
        }
        if(ind2==y.size()){
            return (x.size()-ind1)*costX;
        }
        if(x[ind1]==y[ind2]){
            return dp[ind1][ind2]=check(ind1+1,ind2+1,x,y,costX,costY);
        }
        else{
            return dp[ind1][ind2]=min(check(ind1+1,ind2,x,y,costX,costY)+costX,check(ind1,ind2+1,x,y,costX,costY)+costY);
        }
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        memset(dp,-1,sizeof(dp));
        return check(0,0,x,y,costX,costY);
    }
};


// } Driver Code Ends