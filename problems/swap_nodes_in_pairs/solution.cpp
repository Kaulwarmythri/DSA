/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *nxt = head->next;
        head->next = nxt->next;
        nxt->next = head;
        head = nxt;
        head->next->next = swapPairs(head->next->next);
        
        return head;
    }
};



/*
 ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *prev = NULL, *curr = head, *nxt = head->next;
        while(curr && nxt) {
            if(!prev) {
                curr->next = nxt->next;
                nxt->next = curr;
                head = nxt;
            }else {
                prev->next = nxt;
                curr->next = nxt->next;
                nxt->next = curr;
            }
            prev = curr;
            curr = curr->next;
            if(curr) nxt = curr->next;    
        }
        
        return head;
    }
*/