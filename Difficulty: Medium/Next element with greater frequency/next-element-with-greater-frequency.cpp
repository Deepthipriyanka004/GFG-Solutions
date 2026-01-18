class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);

        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;

        stack<int> st; // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = arr[st.top()];
            }

            st.push(i);
        }

        return ans;
    }
};
