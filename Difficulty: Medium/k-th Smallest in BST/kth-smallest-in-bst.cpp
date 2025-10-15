/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    priority_queue<int> pq;
    void inorder(Node* root, int k) {
        if (!root) return;
        inorder(root->left, k);
        pq.push(root->data);
        if (pq.size() > k) pq.pop(); 
        inorder(root->right, k);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        inorder(root, k);
        if(pq.size()==k)
        return pq.top();
        return -1;
    }
};