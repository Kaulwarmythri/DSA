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
    int maxi = 0;
public:
    int pairSum(ListNode* head) {
        solve(head, head);
        
        return maxi;
    }
    
    void solve(ListNode* &head1, ListNode *head2) {
        if(!head2) return;
        
        solve(head1, head2->next);
        maxi = max(maxi, head1->val + head2->val);
        head1 = head1->next;
    }
};