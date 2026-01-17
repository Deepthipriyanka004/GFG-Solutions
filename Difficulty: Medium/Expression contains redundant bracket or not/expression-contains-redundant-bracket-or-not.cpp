class Solution {
  public:
    bool isOperator(char c){
        if(c == '+' or c == '-' or c == '*' or c == '/')return true;
        return false;
    }
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for(char &c: s){
            if(c == '(' or isOperator(c)){
                st.push(c);
            }
            else if(c == ')'){
                if(st.empty())return true;
                if(!isOperator(st.top())){
                    return true;
                }
                while(isOperator(st.top()))st.pop();
                if(st.empty())return true;
                if(st.top() != '(')return true;
                st.pop();
            }
        }
        return false;
    }
};