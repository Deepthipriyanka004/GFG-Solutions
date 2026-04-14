class Solution {
  public:
    string removeSpaces(string& s) {
        string result = "";
        
        for(char ch : s) {
            if(ch != ' ') {
                result += ch;
            }
        }
        
        return result;
    }
};