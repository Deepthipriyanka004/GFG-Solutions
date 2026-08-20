/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
  public:
	int max_diff = INT_MIN;
	int solve(Node* root) {
		if (root == nullptr)
			return INT_MAX;
		int left = solve(root->left);
		int right = solve(root->right);
		int root_data = root->data;
		max_diff = max({max_diff, root_data - left, root_data - right});
		return min({left, right, root_data});
	}
	int maxDiff(Node* root) {
		// code here
		int x = solve(root);
		return max_diff;
	}
};