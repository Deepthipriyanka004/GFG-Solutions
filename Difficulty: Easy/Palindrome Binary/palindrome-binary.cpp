class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        string s = "";

        // Convert to binary
        while(n){
            if(n % 2 == 0) s.push_back('0');
            else s.push_back('1');
            n = n / 2;
        }

        // Check palindrome
        int l = 0, h = s.size() - 1;
        while(l <= h){
            if(s[l] != s[h]) return false;
            l++;
            h--;
        }

        return true;
    }
};