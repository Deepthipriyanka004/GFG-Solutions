class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> s;
        for (int x : arr) {
            while (!s.empty() && s.back() * x < 0) {
                int top = s.back();
                if (abs(top) > abs(x)) {
                    x = top;
                    s.pop_back();
                }
                else if (abs(top) < abs(x)) s.pop_back();
                else {
                    s.pop_back(); 
                    x = 0; 
                    break;
                }
            }
            if(x!=0)
                s.push_back(x);
        }
        return s;
    }
};