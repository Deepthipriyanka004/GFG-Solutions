class Solution {
  public:
    
    long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }
    
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        
        int n = arr.size();
        
        // Segment Tree
        vector<long long> seg(4 * n);
        
        // Build Tree
        function<void(int,int,int)> build = [&](int idx, int l, int r) {
            if (l == r) {
                seg[idx] = arr[l];
                return;
            }
            
            int mid = (l + r) / 2;
            
            build(2 * idx + 1, l, mid);
            build(2 * idx + 2, mid + 1, r);
            
            seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
        };
        
        // Update
        function<void(int,int,int,int,int)> update =
        [&](int idx, int l, int r, int pos, int val) {
            
            if (l == r) {
                seg[idx] = val;
                return;
            }
            
            int mid = (l + r) / 2;
            
            if (pos <= mid)
                update(2 * idx + 1, l, mid, pos, val);
            else
                update(2 * idx + 2, mid + 1, r, pos, val);
            
            seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
        };
        
        // Range Query
        function<long long(int,int,int,int,int)> query =
        [&](int idx, int l, int r, int ql, int qr) -> long long {
            
            // Complete overlap
            if (ql <= l && r <= qr)
                return seg[idx];
            
            // No overlap
            if (r < ql || l > qr)
                return 1;
            
            int mid = (l + r) / 2;
            
            long long left = query(2 * idx + 1, l, mid, ql, qr);
            long long right = query(2 * idx + 2, mid + 1, r, ql, qr);
            
            return lcm(left, right);
        };
        
        build(0, 0, n - 1);
        
        vector<long long> ans;
        
        for (auto &q : queries) {
            
            // Update Query
            if (q[0] == 1) {
                int index = q[1];
                int value = q[2];
                
                arr[index] = value;
                update(0, 0, n - 1, index, value);
            }
            
            // Range LCM Query
            else {
                int L = q[1];
                int R = q[2];
                
                ans.push_back(query(0, 0, n - 1, L, R));
            }
        }
        
        return ans;
    }
};