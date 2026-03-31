class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        
        int hold = -arr[0];  // holding stock
        int cash = 0;        // not holding
        
        for (int i = 1; i < n; i++) {
            hold = max(hold, cash - arr[i]);
            cash = max(cash, hold + arr[i] - k);
        }
        
        return cash;
    }
};