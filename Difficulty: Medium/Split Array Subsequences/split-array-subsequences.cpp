#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq;     // frequency of each number
        unordered_map<int, int> need;     // how many subsequences are waiting for this number
        
        for (int num : arr)
            freq[num]++;
        
        for (int num : arr) {
            if (freq[num] == 0) continue; // already used
            
            // try to append current number to a previous subsequence
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
            } 
            // try to create a new subsequence of length at least k
            else {
                bool canForm = true;
                for (int i = 0; i < k; i++) {
                    if (freq[num + i] == 0) {
                        canForm = false;
                        break;
                    }
                    freq[num + i]--;
                }
                if (!canForm)
                    return false;
                need[num + k]++;
                continue;
            }
            freq[num]--;
        }
        return true;
    }
};
