/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<int,int> mpp;
    int dfs(Node* root, int curr, int k){
        if(!root) return 0;
        curr += root->data;
        int endsHere = 0;
        if(mpp.find(curr-k) != mpp.end()){
            endsHere += mpp[curr-k];
        }
        mpp[curr]++;
        int total = endsHere + dfs(root->left,curr,k) + dfs(root->right,curr,k);
        if(--mpp[curr] == 0) mpp.erase(curr);
        return total;
    }
    int countAllPaths(Node *root, int k) {
        // code here
        mpp.clear();
        mpp[0] = 1;
        return dfs(root, 0, k);
    }
};