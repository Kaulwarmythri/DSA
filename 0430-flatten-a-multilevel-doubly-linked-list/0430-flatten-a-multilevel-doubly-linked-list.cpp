/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        
        Node *curr = head, *next1 = flatten(head->child), *next2 = flatten(head->next);
        
        if(next1) {
            curr->next = next1;
            curr->next->prev = curr;
            curr->child = NULL;
            while(curr->next) {
                curr = curr->next;
            }
        }
        
        curr->next = next2;
        if(next2) 
            next2->prev = curr;
        
        return head;
    }
};