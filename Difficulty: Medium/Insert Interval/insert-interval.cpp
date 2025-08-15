class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back({newInterval[0],newInterval[1]});
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            int end = ans.back()[1];
            int st = intervals[i][0];
            if(end >= st){
                ans.back()[1] = max(end,intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};