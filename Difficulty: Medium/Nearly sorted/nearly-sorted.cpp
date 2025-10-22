class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        int index = 0;
        
        // Push first k+1 elements into the heap
        for (int i = 0; i <= k && i < n; i++)
            pq.push(arr[i]);
        
        // For remaining elements, extract-min and push next
        for (int i = k + 1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        // Empty remaining elements
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};
