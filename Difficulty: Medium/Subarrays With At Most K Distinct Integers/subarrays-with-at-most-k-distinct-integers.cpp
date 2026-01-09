class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        if (k == 0) return 0;

        unordered_map<int,int> freq;
        int l = 0, ans = 0;

        for (int r = 0; r < arr.size(); r++) {
            freq[arr[r]]++;

            while (freq.size() > k) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0)
                    freq.erase(arr[l]);
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
