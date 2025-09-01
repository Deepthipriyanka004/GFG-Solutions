class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        map<int,set<int>> mp;
        unordered_map<int,int> freq;
        for(int i=0; i<k; i++){
            freq[arr[i]]++;
            int f = freq[arr[i]];
            if(f == 1) {
                mp[f].insert(arr[i]);
            } else {
                mp[f-1].erase(arr[i]);
                if(mp[f-1].empty()) mp.erase(f-1);
                mp[f].insert(arr[i]);
            }
        }
        int sum = 0;
        auto it = prev(mp.end());
        sum += (*it->second.begin());
        int i = 0, j = k;
        while(j < arr.size()){
            freq[arr[i]]--;
            int f = freq[arr[i]];
            if(f == 0){
                freq.erase(arr[i]);
                mp[f+1].erase(arr[i]);
                if(mp[f+1].empty()) mp.erase(f+1);
            } else {
                mp[f+1].erase(arr[i]);
                if(mp[f+1].empty()) mp.erase(f+1);
                mp[f].insert(arr[i]);
            }
            i++;
            freq[arr[j]]++;
            int f1 = freq[arr[j]];
            if(f1 == 1){
                mp[f1].insert(arr[j]);
            } else {
                mp[f1-1].erase(arr[j]);
                if(mp[f1-1].empty()) mp.erase(f1-1);
                mp[f1].insert(arr[j]);
            }
            auto it2 = prev(mp.end());
            sum += (*it2->second.begin());
            j++;
        }
        return sum;
    }
};