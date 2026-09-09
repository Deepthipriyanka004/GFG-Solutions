class Solution {
public:
    int digitSum(long long n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int findMax(int n) {
        string s = to_string(n);

        long long ans = n;
        int maxSum = digitSum(n);

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '0')
                continue;

            string temp = s;

            // Decrease current digit by 1
            temp[i]--;

            // Make all following digits 9
            for (int j = i + 1; j < s.size(); j++) {
                temp[j] = '9';
            }

            long long num = stoll(temp);

            int sum = digitSum(num);

            if (sum > maxSum || (sum == maxSum && num > ans)) {
                maxSum = sum;
                ans = num;
            }
        }

        return ans;
    }
};