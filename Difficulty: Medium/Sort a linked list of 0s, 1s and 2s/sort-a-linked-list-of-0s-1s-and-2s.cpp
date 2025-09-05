/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* curr=head;
        int n=0;
        int zeroCnt = 0;
        int oneCnt = 0;
        int twoCnt = 0;
        while(curr!=NULL){
            if(curr->data ==0) zeroCnt+=1;
            else if(curr->data==1) oneCnt+=1;
            else twoCnt +=1;
            curr=curr->next;
        }
        curr=head;
        while (zeroCnt--) {
            curr->data = 0;
            curr = curr->next;
        }
        while (oneCnt--) {
            curr->data = 1;
            curr = curr->next;
        }
        while (twoCnt--) {
            curr->data = 2;
            curr = curr->next;
        }
        return head;
    }
};