class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();

        // Step 1: Check if all 9s
        bool all9 = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                all9 = false;
                break;
            }
        }

        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }

        // Step 2: Create a copy and mirror
        vector<int> res = num;
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;

        // Check if left side is smaller
        bool leftSmaller = false;
        while (i >= 0 && res[i] == res[j]) {
            i--;
            j++;
        }

        if (i < 0 || res[i] < res[j]) {
            leftSmaller = true;
        }

        // Mirror left to right
        while (i >= 0) {
            res[j] = res[i];
            i--;
            j++;
        }

        // Step 3: If needed, increment middle and propagate carry
        if (leftSmaller) {
            int carry = 1;
            i = mid - 1;

            // odd length
            if (n % 2 == 1) {
                res[mid] += carry;
                carry = res[mid] / 10;
                res[mid] %= 10;
                j = mid + 1;
            } else {
                j = mid;
            }

            // propagate carry
            while (i >= 0) {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;

                res[j] = res[i]; // mirror
                i--;
                j++;
            }
        }

        return res;
    }
};