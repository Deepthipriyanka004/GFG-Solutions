class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        unordered_map<int, int> mp;
        mp.reserve(n);                 // Avoid rehashing
        mp.max_load_factor(0.7);       // Improve performance
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            prefixSum += (a1[i] - a2[i]);
            
            if(prefixSum == 0) {
                maxLen = i + 1;
            }
            
            // Store only first occurrence
            if(mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            } else {
                maxLen = max(maxLen, i - mp[prefixSum]);
            }
        }
        
        return maxLen;
    }
};