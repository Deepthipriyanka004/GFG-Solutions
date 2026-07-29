class Solution {
public:
    int minSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0 || arr[i] != arr[i - 1] + 1)
                count++;
        }
        return count;
    }
};