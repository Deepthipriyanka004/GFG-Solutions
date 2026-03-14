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
    vector<int> topView(Node *root) {
        // code here
        map<int, int> map;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        vector<int> ans;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.second;
            int hd = it.first;
            if (!map.count(hd)) {
                map[hd] = node->data;
            }
            if (node->left) {
                q.push({hd - 1, node->left});
            }
            if (node->right) {
                q.push({hd + 1, node->right});
            }
        }
        for (auto& p : map) {
            ans.push_back(p.second);
        }
        return ans;
    }
};