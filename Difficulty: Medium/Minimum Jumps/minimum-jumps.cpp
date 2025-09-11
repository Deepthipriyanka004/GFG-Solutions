class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), jumps = 0, far = 0, end = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + arr[i]);
            if (i == end) jumps++, end = far;
            if (end >= n - 1) return jumps;
        }
        return -1;
    }
};