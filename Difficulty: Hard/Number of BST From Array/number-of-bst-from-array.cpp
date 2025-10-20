class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> catalan(7, 0);
        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= 6; i++)
            for (int j = 0; j < i; j++)
                catalan[i] += catalan[j] * catalan[i - 1 - j];

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) idx[sortedArr[i]] = i;

        vector<int> result;
        for (int x : arr) {
            int pos = idx[x];
            int left = pos;
            int right = n - pos - 1;
            result.push_back(catalan[left] * catalan[right]);
        }
        return result;
    }
};
