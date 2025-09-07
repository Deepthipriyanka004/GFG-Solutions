/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        for (auto head : arr) {
            if (head) pq.push({head->data, head});
        }
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        while (!pq.empty()) {
            auto [val, node] = pq.top(); pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) {
                pq.push({node->next->data, node->next});
            }
        }
        return dummy->next;
    }
};