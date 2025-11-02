#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        int existing = edges.size();
        int maxPossible = (V * (V - 1)) / 2;
        return maxPossible - existing;
    }
};
