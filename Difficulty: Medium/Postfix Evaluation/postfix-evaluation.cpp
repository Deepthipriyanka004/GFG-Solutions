class Solution {
  public:
    int solve(int v1, int v2, string& s){
        if(s == "+"){return v1+v2;}
        if(s == "-"){return v1-v2;}
        if(s == "*"){return v1*v2;}
        if(s == "/"){
            int res = v1/v2;
            if(v1%v2 != 0 && ((v1<0)^(v2<0))){
                res = res-1;
            }
            return res;
        }
        return (int)pow(v1,v2);
    }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>st;
        unordered_set<string>operators = {"+", "-", "*", "/" , "^"};
        for(auto& s:arr){
            if(operators.count(s)){
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                
                int ans = solve(v1,v2,s);
                st.push(ans);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};