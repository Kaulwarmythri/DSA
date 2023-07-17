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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        
        while(temp1 || temp2) {
            if(!temp1) {
                ListNode *newNode = new ListNode(0);
                newNode->next = l1;
                l1 = newNode;
                
                temp2 = temp2->next;
            } else if(!temp2) {
                ListNode *newNode = new ListNode(0);
                newNode->next = l2;
                l2 = newNode;
                
                temp1 = temp1->next;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        
        solve(l1, l2, carry);
        
        if(carry) {
            ListNode *newNode = new ListNode(carry);
            newNode->next = l1;
            
            l1 = newNode;
        }
        
        return l1;
    }
    
    void solve(ListNode *l1, ListNode *l2, int &carry) {
        if(!l1 && !l2) return;
        
        solve(l1->next, l2->next, carry);
        
        carry += l1->val;
        carry += l2->val;
        
        l1->val = carry % 10;
        
        carry /= 10;
    }
};