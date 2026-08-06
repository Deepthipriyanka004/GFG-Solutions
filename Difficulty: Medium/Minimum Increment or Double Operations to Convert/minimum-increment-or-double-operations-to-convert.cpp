class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int incOps = 0;
        int doubleOps = 0;

        for (int x : arr) {
            incOps += __builtin_popcount(x);

            int bits = 0;
            while (x > 1) {
                x >>= 1;
                bits++;
            }
            doubleOps = max(doubleOps, bits);
        }

        return incOps + doubleOps;
    }
};