/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inOrder(Node* root, vector<int>& temp) {
        if(!root) return;
        inOrder(root->left, temp);
        temp.push_back(root->data);
        inOrder(root->right, temp);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<int> temp;
        inOrder(root, temp);
        auto idx01 = lower_bound(temp.begin(), temp.end(), key);
        auto idx02 = upper_bound(temp.begin(), temp.end(), key);
        Node* pre = NULL;
        Node* suc = NULL;
        // Predecessor: lower_bound - 1
        if(idx01 != temp.begin()) {
            pre = new Node(*(idx01 - 1));  // Dereference the iterator!
        }
        // Successor: upper_bound
        if(idx02 != temp.end()) {
            suc = new Node(*idx02);  // Dereference the iterator!
        }
        return {pre, suc};
    }
};