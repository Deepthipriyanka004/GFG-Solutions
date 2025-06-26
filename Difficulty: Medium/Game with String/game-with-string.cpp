class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>frq(26,0);
        for(int i=0;i<n;i++){
            frq[s[i]-'a']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(frq[i]==0)continue;
            pq.push(frq[i]);
        }
        for(int i=0;i<k;i++){
            int top=pq.top();
            pq.pop();
            top--;
            if(top==0)continue;
            pq.push(top);
        }
        int ans=0;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans+=(top*top);
        }
        return ans;
    }
};