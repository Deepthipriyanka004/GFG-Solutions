class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        vector<int> h(n);
        for (int i = 0; i < (n); ++i) {
            auto e = q.front();
            q.pop();
            h[i] = e;
        }
        
        for(int i = 0, j = n / 2; j < n; i++, j++) {
            q.push(h[i]);
            q.push(h[j]);
        }
    }
};