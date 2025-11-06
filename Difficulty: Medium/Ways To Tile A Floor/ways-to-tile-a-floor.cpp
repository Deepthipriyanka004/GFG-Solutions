class Solution {
  public:
    // int mod = 1e9 + 7;
    long long numberOfWays(long long n) {
        // code here
        long long a = 0, b = 1, c;
        for(long long i=0;i<n;i++) {
            c = (a + b);
            a = b;
            b = c;
        }
        return c;
    }
};