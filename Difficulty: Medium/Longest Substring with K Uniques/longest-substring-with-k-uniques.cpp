class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int left = 0, right = 0;
        int maxLen = -1;
        
        unordered_map<char, int> freq;

        while (right < n) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            if (freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};