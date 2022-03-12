/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node *, Node *> m;
public:
    Node* copyRandomList(Node* head, Node *res = NULL) {
        if(!head) return head;
        
        res = new Node(head->val);
        m[head] = res;
        
        res->next = copyRandomList(head->next, res->next);
        res->random = m[head->random];
        
        return res;
    }
};