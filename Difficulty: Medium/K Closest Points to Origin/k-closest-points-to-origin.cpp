class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to store pair {distance, {x, y}}
        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &p : points) {
            int x = p[0], y = p[1];
            int dist = x*x + y*y;  // squared distance
            pq.push({dist, {x, y}});

            // Keep only k closest points
            if (pq.size() > k) pq.pop();
        }

        // Extract results from heap
        vector<vector<int>> result;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            result.push_back({top.second.first, top.second.second});
        }

        return result;
    }
};
