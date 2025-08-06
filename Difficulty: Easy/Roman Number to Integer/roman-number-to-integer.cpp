class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> priority;
        priority['I'] = 1;
        priority['V'] = 2;
        priority['X'] = 3;
        priority['L'] = 4;
        priority['C'] = 5;
        priority['D'] = 6;
        priority['M'] = 7;
        unordered_map<char, int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        int n=s.size();
        int ans = value[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(priority[s[i+1]] > priority[s[i]])
              ans -= value[s[i]];
            else
              ans += value[s[i]];
        }
        return ans;
    }
};