class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int N=color.size();
        stack <int> s;
        for(int i=0;i<N;i++){
            if(s.size()>0){
                if(color[s.top()]==color[i] and radius[s.top()]==radius[i]){
                    s.pop();
                    continue;
                }
            }
            s.push(i);
        }
        return s.size();
    }
};