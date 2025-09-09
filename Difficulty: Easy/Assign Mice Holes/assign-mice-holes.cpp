class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int maxm=INT_MIN;
        for(int i=0;i<holes.size();i++){
            if(mices[i]<0 && holes[i]<0)
                maxm=max(maxm,abs(abs(mices[i])-abs(holes[i])));
            else if(mices[i]<0 && holes[i]>0||mices[i]>0 && holes[i]<0){
                maxm=max(maxm,abs(mices[i])+abs(holes[i]));
            }
            else
                maxm=max(maxm,abs(abs(mices[i])-abs(holes[i])));
        }
        return maxm;
    }
};