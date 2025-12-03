class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int mask, int i, vector<vector<int>>& cost) {
        // If all cities visited, return cost to go back to 0
        if(mask == (1 << n) - 1) 
            return cost[i][0];

        if(dp[mask][i] != -1)
            return dp[mask][i];

        int ans = INT_MAX;

        // Try going to an unvisited city
        for(int j = 0; j < n; j++) {
            if(!(mask & (1 << j))) { // j not visited
                ans = min(ans, cost[i][j] + solve(mask | (1 << j), j, cost));
            }
        }

        return dp[mask][i] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        dp.assign(1 << n, vector<int>(n, -1));
        return solve(1, 0, cost); // mask = 1 → city 0 visited
    }
};
