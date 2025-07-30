class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        int count = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(map.find(sum-k) != map.end()){
                count += map[sum-k];
            }
            map[sum]++;
        }
        return count;
    }
};