/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        int leftSubtreeSize = getSize(root->left);
        int rightSubtreeSize = getSize(root->right);
        int totalSize = leftSubtreeSize + rightSubtreeSize + 1;
        return totalSize;
    }
};