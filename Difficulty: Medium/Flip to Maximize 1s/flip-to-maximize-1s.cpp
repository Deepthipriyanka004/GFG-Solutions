class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;

        // Count existing ones
        for(int num : arr) {
            if(num == 1)
                totalOnes++;
        }

        int currGain = 0, maxGain = 0;

        for(int num : arr) {
            int value = (num == 0) ? 1 : -1;

            currGain = max(value, currGain + value);
            maxGain = max(maxGain, currGain);
        }

        return totalOnes + maxGain;
    }
};