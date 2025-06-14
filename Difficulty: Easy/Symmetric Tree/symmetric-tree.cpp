/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(struct Node* root, struct Node* root1) {
        if(root == nullptr && root1 == nullptr ) {
            return true;
        }
        if(root == nullptr || root1 == nullptr|| root->data != root1->data) {
            return false;
        }
        bool left = solve(root->left, root1->right);
        bool right = solve(root->right, root1->left);
        return left && right;
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root == nullptr) {
            return true;
        }
	    return solve(root->left, root->right);
    }
};