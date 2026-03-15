/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int, vector<int>> m;
        queue<tuple<Node*,int>> q;
        q.push({root,0});
        while (q.size()) {
            auto [n,c] = q.front(); 
            q.pop();
            m[c].push_back(n->data);
            if (n->left) q.emplace(n->left,c - 1);
            if (n->right) q.emplace(n->right,c + 1);
        }
        vector<vector<int>> ans;
        for(auto it:m) ans.push_back(it.second);
        return ans;
    }
};