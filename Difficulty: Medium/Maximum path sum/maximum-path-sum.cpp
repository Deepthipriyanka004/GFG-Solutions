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
    int calculateMaxSum(Node *root, int &ans) {
        if(root == NULL) return 0;
        int sum = root->data;
        int leftSum = calculateMaxSum(root->left, ans);
        int rightSum = calculateMaxSum(root->right, ans);
        ans = max(ans, sum + max(0, leftSum) + max(0, rightSum));
        return sum + max(0, max(leftSum, rightSum));
    }
    int findMaxSum(Node *root) {
        // code here
        int ans = root->data;
        calculateMaxSum(root, ans);
        return ans;
    }
};