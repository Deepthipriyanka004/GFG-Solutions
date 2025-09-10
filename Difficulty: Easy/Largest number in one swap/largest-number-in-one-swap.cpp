class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        vector<int>v(10,-1);
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            int dig = s[i]-'0';
            if(v[dig]==-1) v[dig]=i;
        }
        for(int i=0;i<n;i++){    // O(n)
            int dig = s[i]-'0';
            for(int j=9;j>=0;j--){   // O(9)
                if(v[j]!=-1 && v[j]>i && j > dig){
                    swap(s[i],s[v[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};