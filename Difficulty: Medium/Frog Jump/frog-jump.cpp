class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        if(height.size() == 1)return 0;
        if(height.size() == 2)return abs(height[0]-height[1]);
        if(height.size() == 3)return abs(height[0]-height[2]);
        int a = abs(height[0]-height[1]);
        int b = abs(height[0]-height[2]);
        for(int i = 3;i<height.size();i++){
            int store = b;
            b = min(a+abs(height[i] - height[i-2]), b+abs(height[i] - height[i-1]));
            a = store;
        }
        return b;
    }
};