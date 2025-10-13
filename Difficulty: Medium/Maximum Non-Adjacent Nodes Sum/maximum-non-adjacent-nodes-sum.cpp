/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0}; // {include, exclude}
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // If we include current node, we cannot include its children
        int include = root->data + left.second + right.second;
        
        // If we exclude current node, we can include or exclude children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }

    int getMaxSum(Node* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};
