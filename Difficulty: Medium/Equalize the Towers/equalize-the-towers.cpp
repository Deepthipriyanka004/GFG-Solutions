class Solution {
  public:
    int FindCost(int h , vector<int> &heights , vector<int> &cost){
        int n = heights.size() , Cost = 0;
        for(int i = 0; i < n; i++)
            Cost += abs(h - heights[i]) * cost[i];
        return Cost;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int s = INT_MAX , e = INT_MIN;
        for(int x : heights){
            s = min(s , x);
            e = max(e , x);
        }
        int ans = INT_MAX;
        while(s <= e){
            int m = (s + e) / 2;
            int c1 = FindCost(m , heights , cost);
            int c2 = FindCost(m + 1 , heights , cost);
            if(c1 <= c2)
                ans = c1 , e = m - 1;
            else
                s = m + 1;
        }
        return ans;
    }
};