/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> inord;
    void Inorder(Node* root){
        if(!root)return;
        Inorder(root->left);
        inord.push_back(root->data);
        Inorder(root->right);
    }
    int findMedian(Node* root) {
        // Code here
        Inorder(root);
        int n = inord.size();
        if(n%2){
            return inord[n/2];
        }
        return inord[n/2-1];
    }
};