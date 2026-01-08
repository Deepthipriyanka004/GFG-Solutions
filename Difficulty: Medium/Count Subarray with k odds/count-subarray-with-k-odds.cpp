class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1; // prefix sum 0 exists once
        
        int prefix = 0, ans = 0;
        
        for(int x : arr){
            if(x % 2 != 0) prefix++; // count odd as 1
            
            if(freq.find(prefix - k) != freq.end())
                ans += freq[prefix - k];
            
            freq[prefix]++;
        }
        
        return ans;
    }
};
