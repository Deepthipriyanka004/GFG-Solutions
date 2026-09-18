/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	void solve(Node* root, int &a, int &mini) {
		if (root == NULL) {
			return ;
		}
		solve(root->left, a, mini);
		if (a != -1) {
			mini = min(mini, root->data - a);
		}
		a = root->data;
		solve(root->right, a, mini);
		return ;
	}
	int absDiff(Node *root) {
		// code here
		int a = -1;
		int mini = INT_MAX;
		solve(root, a, mini);
		return mini;
	}
};