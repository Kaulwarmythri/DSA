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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if(!l1 && !l2) 
            return carry ? new ListNode(carry) : NULL;
        
        int sum = 0;
        sum += l1 ? l1->val : NULL;
        sum += l2? l2->val : NULL;
        sum += carry;
        
        ListNode *newNode = new ListNode(sum % 10);
        
        newNode->next = addTwoNumbers(l1 ? l1->next : NULL, l2 ? l2->next : NULL, sum / 10);
        
        return newNode;
    }
};