/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    pair<int,pair<int,int>> helper(Node* root,int &ans){
        if(!root)
            return {0,{INT_MIN,INT_MAX}};
        auto left=helper(root->left,ans);
        auto right=helper(root->right,ans);
        if(left.second.first<root->data and root->data<right.second.second){
            ans=max(ans,left.first+right.first+1);
            return {left.first+right.first+1,{max(root->data,right.second.first),min(root->data,left.second.second)}};
        }
        return {0,{INT_MAX,INT_MIN}};
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        int ans=0;
        helper(root,ans);
        return ans;
    }
};