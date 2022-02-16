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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int n = 0;
        while(curr) curr = curr->next, n++;
        return reverseGroups(head, k, n);
    }
    
    ListNode *reverseGroups(ListNode *head, int k, int n){
        int cnt = 0;
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        while(curr && cnt < k && n-k >= 0){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        n = n - k;
        if(curr && n-k >= 0) head->next = reverseGroups(nxt, k, n);
        else head->next = nxt;
        
        return prev;
        
        
    }
};