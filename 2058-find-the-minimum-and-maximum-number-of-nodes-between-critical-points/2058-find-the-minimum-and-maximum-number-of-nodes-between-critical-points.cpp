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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int n = 1;
        vector<int> cp;
        ListNode *cur = head->next, *pre = head, *nxt = head->next->next;
        
        while(cur->next) {
            if((pre->val > cur->val && nxt->val > cur->val) || (pre->val < cur->val && nxt->val < cur->val)) {
                cp.push_back(n);
            }
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
            n++;
        }
        
        vector<int> ans = {-1, -1};
        if(cp.size() >= 2) {
            ans[1] = cp[cp.size()-1] - cp[0];
            int mini = INT_MAX;
            for(int i=1; i<cp.size(); i++) {
                mini = min(mini, cp[i] - cp[i-1]);
            }
            ans[0] = mini;
        }
        return ans;
    }
};