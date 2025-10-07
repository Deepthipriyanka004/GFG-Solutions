/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root, 0});
        while(q.size()){
            int size = q.size();
            while(size--){
                auto elem = q.front();
                q.pop();
                mpp[elem.second] = elem.first->data;
                if(elem.first->left){
                    q.push({elem.first->left, elem.second-1});
                }
                if(elem.first->right){
                    q.push({elem.first->right, elem.second+1});
                }
            }
        }
        vector<int>ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};