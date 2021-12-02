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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> ans(k);
        ListNode *curr = head, *temp, *next;
        int n = 0;
        while(curr){
            curr = curr->next;
            n++;
        }
        curr = head;
        int width=n/k, extra=n%k;
        for(int i=0;i<k;i++){
            temp = curr;
            for(int j=1; j<width+(i < extra ? 1 : 0); j++){
                if(curr) curr = curr->next;
            }
            if(curr){
                next = curr->next;
                curr->next = NULL;
                curr = next;
            }
            ans[i] = temp;
        }
        
        return ans;
        
        
    }
};
