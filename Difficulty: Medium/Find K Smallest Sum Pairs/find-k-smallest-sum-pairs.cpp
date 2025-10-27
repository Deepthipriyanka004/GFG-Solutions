class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>> ans;
        int n1=arr1.size();
        int n2=arr2.size();
        if (n1==0|| n2==0 || k==0){
            return ans;
        }
        typedef tuple<int,int,int> T;
        priority_queue<T,vector<T>,greater<T>> pq;//{sum,pos1,pos2}
        for(int i=0;i<min(n1,k);i++){
            pq.push({arr1[i]+arr2[0],i,0});
        }
        while(k-- && !pq.empty()){
            auto [sum,i,j] = pq.top();
            pq.pop();
            ans.push_back({arr1[i],arr2[j]});
            if(j+1<n2){
                pq.push({arr1[i]+arr2[j+1],i,j+1});
            }
        }
        return ans;
    }
};