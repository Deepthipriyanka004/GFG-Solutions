class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        // Correct k
        if (isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;

        if (k >= n)
            return "-1";

        string st;

        for (char ch : s) {
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        while (k > 0) {
            st.pop_back();
            k--;
        }

        return st.empty() ? "-1" : st;
    }
};