class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size(), need = (n + 1) / 2, total = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : arr) pq.push(x % k ? k - x % k : 0);
        while (need--) total += pq.top(), pq.pop();
        return total;
    }
};