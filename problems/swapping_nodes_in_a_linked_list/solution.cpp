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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *nth=head, *fast=head, *slow=head;
        
        for(int i=0; i<k-1; i++) fast = fast->next, nth = fast;
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        swap(slow->val, nth->val);
        
        return head;
        
    }
};