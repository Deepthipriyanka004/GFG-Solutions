class Node{
  public:
    Node *child[26];
    Node(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};
class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Node *root = new Node();
        int n = s.size();
        int count=0;
        for(int i=0;i<n;i++){
            Node* temp = root;
            for(int j=i;j<n;j++){
                int ind = s[j]-97;
                if(temp->child[ind] == NULL){
                    temp->child[ind] = new Node();
                    count++;
                }
                temp = temp->child[ind];
            }
        }
        return count;
    }
};