class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> result(n, -1);             // man -> woman
        vector<int> partnerOfWoman(n, -1);     // woman -> man
        vector<int> nextProposal(n, 0);        // next woman index for each man
        
        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        
        // Build ranking matrix for women
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }
        
        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();
            
            int w = men[m][nextProposal[m]];
            nextProposal[m]++;
            
            // If woman is free
            if (partnerOfWoman[w] == -1) {
                partnerOfWoman[w] = m;
                result[m] = w;
            }
            else {
                int currentMan = partnerOfWoman[w];
                
                // Check if she prefers new man over current
                if (rank[w][m] < rank[w][currentMan]) {
                    partnerOfWoman[w] = m;
                    result[m] = w;
                    
                    // previous man becomes free
                    freeMen.push(currentMan);
                } else {
                    // she rejects new man
                    freeMen.push(m);
                }
            }
        }
        
        return result;
    }
};