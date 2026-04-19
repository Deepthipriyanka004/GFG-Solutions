class Solution {
  public:
    bool isPower(int x, int y) {
        if (y == 1) return true;      // x^0 = 1
        if (x == 1) return false;     // 1 can only generate 1
        
        while (y % x == 0) {
            y /= x;
        }
        
        return (y == 1);
    }
};