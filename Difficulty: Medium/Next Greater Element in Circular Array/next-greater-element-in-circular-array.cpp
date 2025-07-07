class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i = 0;i<2*n;i++){
            while(!st.empty() && arr[i%n]>arr[st.top()]){
                nge[st.top()] = arr[i%n];
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        return nge;
    }
};