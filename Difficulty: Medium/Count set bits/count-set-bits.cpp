class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int sum = 0;
        while (n > 0) {
            int x = log2(n);  // Largest power of 2 ≤ n
            sum += x * (1 << (x - 1)) + (n - (1 << x) + 1);
            n -= (1 << x);  // Reduce n to process remaining numbers
        }
        return sum;
    }
};