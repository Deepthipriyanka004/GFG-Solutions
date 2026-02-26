class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        
        if(s1.size() != s2.size()) return false;
        
        int m1[256] = {0};
        int m2[256] = {0};
        
        for(int i = 0; i < s1.size(); i++){
            
            // If both are not mapped yet
            if(m1[s1[i]] == 0 && m2[s2[i]] == 0){
                m1[s1[i]] = s2[i];
                m2[s2[i]] = s1[i];
            }
            // If already mapped but mismatch
            else if(m1[s1[i]] != s2[i] || m2[s2[i]] != s1[i]){
                return false;
            }
        }
        
        return true;
    }
};