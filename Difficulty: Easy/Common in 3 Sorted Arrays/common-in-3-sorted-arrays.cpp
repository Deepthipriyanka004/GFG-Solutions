class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> result;

        while (i < a.size() && j < b.size() && k < c.size()) {
            
            // If all elements are equal
            if (a[i] == b[j] && b[j] == c[k]) {
                // Avoid duplicates in result
                if (result.empty() || result.back() != a[i])
                    result.push_back(a[i]);
                
                i++;
                j++;
                k++;
            }
            // Move pointer of smallest element
            else if (a[i] < b[j]) {
                i++;
            }
            else if (b[j] < c[k]) {
                j++;
            }
            else {
                k++;
            }
        }

        return result;
    }
};