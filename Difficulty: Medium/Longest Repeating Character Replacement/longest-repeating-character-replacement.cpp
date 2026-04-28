class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.length();
        int result = 0 ; 
        for(char ch = 'A'; ch <= 'Z'; ch++){
           int non_ch = 0; 
           int i = 0 ; 
           int j = 0 ; 
           while( j < n ){
               if(s[j] != ch){
                   non_ch++;
               }
               while(i <= j && non_ch > k ){
                   if(s[i] != ch){
                       non_ch--;
                      
                   }
                   i++;
               }
               result = max(result, j - i + 1);
               j++;
           }
       }
       return result;
    }
};