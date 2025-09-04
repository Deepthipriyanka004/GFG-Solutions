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
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head == NULL) return head;
        Node* curr= head, *prev = NULL;
        Node* next = curr->next;
        int cnt =0;
        // Normal Iterative Reversal but just doing it for k nodes each time & calling recursion for the rest
        while(curr != NULL && cnt < k ){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        // Recursion step
        if(next!= NULL){
            // Connecting all the nodes after each recursion call returns back
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};