/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (!root1 || !root2)
            return root1 == root2;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {

            int n1 = q1.size();
            int n2 = q2.size();

            // Different number of nodes at same level
            if (n1 != n2)
                return false;

            vector<int> level1, level2;

            for (int i = 0; i < n1; i++) {
                Node* node1 = q1.front();
                q1.pop();

                Node* node2 = q2.front();
                q2.pop();

                level1.push_back(node1->data);
                level2.push_back(node2->data);

                if (node1->left)
                    q1.push(node1->left);
                if (node1->right)
                    q1.push(node1->right);

                if (node2->left)
                    q2.push(node2->left);
                if (node2->right)
                    q2.push(node2->right);
            }

            sort(level1.begin(), level1.end());
            sort(level2.begin(), level2.end());

            if (level1 != level2)
                return false;
        }

        return q1.empty() && q2.empty();
    }
};