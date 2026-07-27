class Solution {
public:
    unordered_map<int, int> pos;
    int preIndex = 0;

    Node* build(vector<int>& pre, vector<int>& preMirror, int l, int r) {
        if (preIndex >= pre.size() || l > r)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        // Leaf node
        if (l == r || preIndex >= pre.size())
            return root;

        int idx = pos[pre[preIndex]];

        root->left = build(pre, preMirror, idx, r);
        root->right = build(pre, preMirror, l + 1, idx - 1);

        return root;
    }

    Node* constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n = preMirror.size();

        for (int i = 0; i < n; i++)
            pos[preMirror[i]] = i;

        preIndex = 0;
        return build(pre, preMirror, 0, n - 1);
    }
};