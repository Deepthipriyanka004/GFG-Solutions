class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int hIdx = 0;
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());
        for(int i=0; i<n; i++){
            if(citations[i] >= i+1){
                hIdx = i+1;
            }
        }
        return hIdx;
    }
};