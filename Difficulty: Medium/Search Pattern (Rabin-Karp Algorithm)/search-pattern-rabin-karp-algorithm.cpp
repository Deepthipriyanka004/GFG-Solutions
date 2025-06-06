class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        if(pat == txt) return {1};
        int n = txt.length();
        int m = pat.length();
        vector<int> ans;
        unordered_map<char, int> patMap;
        unordered_map<char, int> txtMap;
        for(int i=0; i<m; ++i){
            txtMap[txt[i]]++;
            patMap[pat[i]]++;
        } 
        // now keep the window of size = m, and start sliding the window, wherever the txtMap == patMap, then check substring for that window is equal to pat or not
        int l=0, r=m-1;
        while(r<n){
            if(txtMap == patMap){
                if (txt.substr(l, m) == pat) {
                    ans.push_back(l + 1);
                }
            }
            txtMap[txt[l]]--;
            if(txtMap[txt[l]] == 0) txtMap.erase(txt[l]);
            ++l;
            ++r;
            txtMap[txt[r]]++;
        }
        return ans;
    }
};