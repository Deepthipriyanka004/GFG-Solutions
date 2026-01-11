class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int start = -1, minLen = n1 + 1;
        
        int i = 0, j = 0;
        
        while (i < n1) {
            // 1. Forward Pass: Find s2 as a subsequence in s1
            if (s1[i] == s2[j]) {
                j++;
            }
            
            // If we found all characters of s2
            if (j == n2) {
                int end = i; // End of the current window
                j--; // Move back to the last char of s2
                
                // 2. Backward Pass: Shrink the window to find the optimal start
                int k = i;
                while (k >= 0 && j >= 0) {
                    if (s1[k] == s2[j]) {
                        j--;
                    }
                    if (j < 0) break;
                    k--;
                }
                
                // k is now the optimized start index of this window
                int currentLen = end - k + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    start = k;
                }
                
                // Reset pointers for the next search
                // Start searching again from k + 1 to find a potentially better/earlier window
                i = k + 1;
                j = 0;
            } else {
                i++;
            }
        }
        
        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};