class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        
        unordered_set<int> st;
        
        // Insert elements of a
        for(int i = 0; i < a.size(); i++) {
            st.insert(a[i]);
        }
        
        // Insert elements of b
        for(int i = 0; i < b.size(); i++) {
            st.insert(b[i]);
        }
        
        // Convert set to vector
        vector<int> result(st.begin(), st.end());
        
        return result;
    }
};