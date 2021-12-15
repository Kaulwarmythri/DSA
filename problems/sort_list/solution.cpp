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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow=head, *fast=head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        ListNode *A = sortList(head), *B = sortList(head2);
        ListNode *final_head = merge(A, B);   
        
        return final_head;
    }
    ListNode *merge(ListNode *A, ListNode *B){
        ListNode *head;
        if(A->val <= B->val){
            head = A;
            A = A->next;   
        }else{
            head = B;
            B = B->next;
        }
        ListNode *curr = head;
        while(A && B){
            if(A->val <= B->val){
                curr->next = A;
                curr = A;
                A = A->next;
            }else{
                curr->next = B;
                curr = B;
                B = B->next;
            }
        }
        if(A) curr->next = A;
        if(B) curr->next = B;
        
        return head;
    }
};
