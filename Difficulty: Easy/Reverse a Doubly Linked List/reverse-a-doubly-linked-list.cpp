/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node* ans;
    Node* iterator(Node *head){
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            ans=head;
            return head;
        }
        else{
            Node* temp=iterator(head->next);
            temp->next=head;
            temp=temp->next;
            return temp;
        }
    }
    Node *reverse(Node *head) {
        // code here
        ans=NULL;
        Node* x=iterator(head);
        x->next=NULL;
        return ans;
    }
};