/*** Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
            
        ListNode *temp1 = head, *temp2 = head;
        
        int cnt = 0;
        while(temp1){
            temp1 = temp1->next;
            cnt++;
        }
        
        temp1 = head;
        k = k%cnt;
        
        for(int i=1; i<(cnt - k); i++){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp2->next) temp2 = temp2->next;
        
        temp2->next = head;
        head = temp1->next;
        temp1->next = NULL;
        
        return head;
    }
};