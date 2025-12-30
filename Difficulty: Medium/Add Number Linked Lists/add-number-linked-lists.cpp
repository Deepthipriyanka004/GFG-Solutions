/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* skipLeadingZeros(Node* head) {
        while (head != nullptr && head->data == 0) {
            head = head->next;
        }
        return head == nullptr ? new Node(0) : head;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = skipLeadingZeros(head1);
        head2 = skipLeadingZeros(head2);
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;
        
        while (head1 != nullptr || head2 != nullptr || carry != 0) {
            int sum = carry;
            if (head1 != nullptr) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2 != nullptr) {
                sum += head2->data;
                head2 = head2->next;
            }
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
        
        Node* result = reverse(dummy->next);
        return skipLeadingZeros(result);
    }
};