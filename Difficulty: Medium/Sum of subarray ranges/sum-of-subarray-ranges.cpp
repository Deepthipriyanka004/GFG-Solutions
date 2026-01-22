class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sumMin = 0, sumMax = 0;
        vector<int> left(n), right(n);
        stack<int> st;

        // -------- SUM OF SUBARRAY MINIMUMS --------
        // Previous smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller or equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            sumMin += (long long)arr[i] * left[i] * right[i];

        while (!st.empty()) st.pop();

        // -------- SUM OF SUBARRAY MAXIMUMS --------
        // Previous greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next greater or equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            sumMax += (long long)arr[i] * left[i] * right[i];

        return (int)(sumMax - sumMin);
    }
};
