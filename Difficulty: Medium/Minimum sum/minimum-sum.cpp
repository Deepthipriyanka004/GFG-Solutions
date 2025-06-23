class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(begin(arr), end(arr), greater<int>());
        int n = arr.size();
        int carry = 0;
        string res = "";
        for(int i = 0; i < n; i += 2){
            int sum = 0;
            sum += arr[i];
            if(i+1 < n)
                sum += arr[i+1];
            sum += carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
        }
        if(carry) res += carry + '0';
        while(!res.empty() && res.back() == '0') res.pop_back();
        reverse(begin(res), end(res));
        return res;
    }
};
