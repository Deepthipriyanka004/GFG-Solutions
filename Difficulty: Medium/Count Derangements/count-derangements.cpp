class Solution {
  public:
    int derangeCount(int n) {
        // code here
        if(n == 1) return 0;
        if(n == 2) return 1;
        return (n - 1) * (derangeCount(n - 1) + derangeCount(n - 2));
    }
};