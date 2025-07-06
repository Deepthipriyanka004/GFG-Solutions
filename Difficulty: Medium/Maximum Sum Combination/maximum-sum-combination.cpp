class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        priority_queue<tuple<int, int, int>> pq;
        unordered_set<long long> vis;
        pq.emplace(a[0] + b[0], 0, 0);
        vis.insert(0);
        vector<int> res;
        while (res.size() < k) {
            int sum = get<0>(pq.top());
            int i = get<1>(pq.top());
            int j = get<2>(pq.top());
            pq.pop();
            res.push_back(sum);
            if (i + 1 < n && vis.insert((long long)(i + 1) * n + j).second)
                pq.emplace(a[i + 1] + b[j], i + 1, j);
            if (j + 1 < n && vis.insert((long long)i * n + j + 1).second)
                pq.emplace(a[i] + b[j + 1], i, j + 1);
        }
        return res;
    }
};