class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int ans = 0;
        stack<char>st;
        int o = 0;
        for(auto it : s){
            if(it == '('){
                st.push(it);
                continue;
            }
            if(st.size()){
                st.pop();
            }
        }
        o = st.size();
        while(st.size())st.pop();
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == ')'){
                st.push(s[i]);
                continue;
            }
            if(st.size()){
                st.pop();
            }
        }
        int c = st.size();
        return o + c;
    }
};