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
        Node *ptr=head, *temp, *runner;
        while(ptr){
            if(ptr->child){
                temp = ptr->next;
                ptr->next = ptr->child;
                ptr->next->prev = ptr;
                ptr->child = NULL;
                
                runner = ptr->next; 
                while(runner->next) runner=runner->next;
                runner->next = temp;
                if(runner->next) runner->next->prev = runner;
            
                
            
            }
            
            ptr = ptr->next;  
        }
        
        return head;
    }
    
};