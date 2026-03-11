class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int ans = 0;
        int n = arr.size();
        stack<int> st;
        vector<int> left(n,-1),right(n,n);
        //calculation of previous smallest element index
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //calculation of next smallest element index
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans += (i-left[i])*(right[i]-i)*arr[i];
        }
        return ans;
    }
};