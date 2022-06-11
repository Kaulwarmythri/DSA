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
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
    
    bool check(ListNode* &head1, ListNode *head2) {
        if(!head2) return true;
        
        bool isPal = check(head1, head2->next);
        if(head1->val != head2->val) return false;
        head1 = head1->next;
        
        return isPal;
    }
};