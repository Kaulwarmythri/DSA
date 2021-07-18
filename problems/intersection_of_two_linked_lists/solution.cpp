/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){return NULL;}
        ListNode *currA = headA, *currB = headB;
        while(currA != currB && currA != NULL && currB != NULL){
            currA = currA->next;
            currB = currB->next;
            
            if(currA == currB){return currA;}
            if(currA == NULL) currA = headB; 
            if(currB == NULL) currB = headA;
        }
        
        return currA;
        
    }
};