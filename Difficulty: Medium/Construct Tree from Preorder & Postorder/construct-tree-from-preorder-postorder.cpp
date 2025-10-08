/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    Node* constructTree(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postorderIndexMap;
        int n = postorder.size();

        for (int i = 0; i < n; ++i) {
            postorderIndexMap[postorder[i]] = i;
        }

        function<Node*(int, int, int, int)> buildTree = [&](int preStart, int preEnd,
                                                            int postStart, int postEnd) -> Node* {
            if (preStart > preEnd) {
                return nullptr;
            }

            Node* root = new Node(preorder[preStart]);

            if (preStart == preEnd) {
                return root;
            }

            int leftRootValue = preorder[preStart + 1];
            int leftRootIndexInPost = postorderIndexMap[leftRootValue];
            int leftSubtreeSize = leftRootIndexInPost - postStart + 1;

            root->left = buildTree(preStart + 1, preStart + leftSubtreeSize,
                                   postStart, leftRootIndexInPost);

            root->right = buildTree(preStart + leftSubtreeSize + 1, preEnd,
                                    leftRootIndexInPost + 1, postEnd - 1);

            return root;
        };

        return buildTree(0, n - 1, 0, n - 1);
    }
};
