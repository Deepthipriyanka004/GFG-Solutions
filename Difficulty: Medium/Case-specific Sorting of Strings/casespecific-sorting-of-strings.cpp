class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int> upper(26,0),lower(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                upper[s[i]-'A']++;
            }
            else{
                lower[s[i]-'a']++;
            }
        }
        
        int ind1=0,ind2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z'){
                while(upper[ind1]==0) ind1++;
                s[i]= char(ind1+'A');
                upper[ind1]--;
            }
            else{
                while(lower[ind2]==0) ind2++;
                s[i]= char(ind2+'a');
                lower[ind2]--;
            }
        }
        return s;
    }
};