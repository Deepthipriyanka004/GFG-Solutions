class Solution {
  public:
    int countWays(int n, int k) {
        if (n == 1) return k;
        
        long same = k;              // for n = 2
        long diff = (long)k * (k - 1);
        
        for (int i = 3; i <= n; i++) {
            long newSame = diff;
            long newDiff = (same + diff) * (k - 1);
            
            same = newSame;
            diff = newDiff;
        }
        
        return same + diff;
    }
};