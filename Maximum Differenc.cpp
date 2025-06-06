class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> left, right;
        stack<int> st, st1;

        // Nearest smaller to left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                left.push_back(0);
            else
                left.push_back(arr[st.top()]);
            st.push(i);
        }

        // Nearest smaller to right
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[st1.top()] >= arr[i])
                st1.pop();
            if (st1.empty())
                right.push_back(0);
            else
                right.push_back(arr[st1.top()]);
            st1.push(i);
        }

        reverse(right.begin(), right.end());

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, abs(left[i] - right[i]));
        }

        return maxi;
    }
};
