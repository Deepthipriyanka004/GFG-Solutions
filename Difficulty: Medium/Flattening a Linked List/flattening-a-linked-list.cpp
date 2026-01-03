class Solution {
  public:
    
    // Function to merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        
        result->next = NULL; // Important
        return result;
    }
    
    Node* flatten(Node* root) {
        // Base case
        if (!root || !root->next)
            return root;
        
        // Flatten the rest of the list
        root->next = flatten(root->next);
        
        // Merge current list with flattened next list
        root = merge(root, root->next);
        
        return root;
    }
};
