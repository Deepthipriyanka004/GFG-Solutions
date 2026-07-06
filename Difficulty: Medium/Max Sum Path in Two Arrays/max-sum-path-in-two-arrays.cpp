class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int i = 0,j = 0,sumA = 0,sumB = 0,answer = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                sumA += a[i];
                i++;
            } 
            else if (a[i] > b[j]) {
                sumB += b[j];
                j++;
            } 
            else {
                answer += max(sumA, sumB);
                answer += a[i];
                sumA = 0;
                sumB = 0;
                i++;
                j++;
            }
        }
        while (i < a.size()) {
            sumA += a[i];
            i++;
        }
        while (j < b.size()) {
            sumB += b[j];
            j++;
        }
        answer += max(sumA, sumB);
        return answer;
    }
};