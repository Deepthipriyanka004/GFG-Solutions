/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;

	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	int getCount(Node *root, int k) {
		// code here
		int lvl = 0;
		queue<Node*> q;
		q.push(root);
		int ans = 0;
		while (!q.empty()) {
			int size = q.size();
			lvl++;
			for (int i = 0; i<size; i++) {
				Node* node = q.front();
				q.pop();
				if (node->left != NULL)q.push(node->left);
				if (node->right != NULL)q.push(node->right);
				if (node->left == NULL && node->right == NULL) {
					if (k >= lvl) {
						k -= lvl;
						ans++;
					}
				}
			}
		}
		return ans;
	}
};