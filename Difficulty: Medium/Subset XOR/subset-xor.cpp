class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        
        // XOR of 1 to n using formula
        int xorAll;
        if (n % 4 == 0) xorAll = n;
        else if (n % 4 == 1) xorAll = 1;
        else if (n % 4 == 2) xorAll = n + 1;
        else xorAll = 0;
        
        if (xorAll == n) {
            // best case - use all numbers
            for (int i = 1; i <= n; i++) ans.push_back(i);
        }
        else if (xorAll == 0) {
            // remove largest to maintain lexicographically smallest
            for (int i = 1; i < n; i++) ans.push_back(i);
        }
        else {
            // remove the number that fixes XOR to n
            int toRemove = xorAll ^ n;
            for (int i = 1; i <= n; i++) {
                if (i != toRemove) ans.push_back(i);
            }
        }
        
        return ans;
    }
};
