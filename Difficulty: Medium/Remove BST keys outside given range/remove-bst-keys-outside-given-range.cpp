/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(!root)return nullptr;
        if(root->data < l)return removekeys(root->right, l, r);
        if(root->data > r)return removekeys(root->left, l, r);
        Node* left = removekeys(root->left, l, r);
        Node* right = removekeys(root->right, l, r);
        root->left = left;
        root->right = right;
        return root;
    }
};