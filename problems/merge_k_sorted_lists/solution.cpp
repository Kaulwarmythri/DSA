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
    struct compare{
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for(auto li : lists){
            if(li) pq.push(li);
        }
        
        if(!pq.size()) return NULL;
        ListNode *dummy = new ListNode(0), *temp = dummy;
        while(pq.size()){
            auto curr = pq.top(); pq.pop();
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
            if(curr) pq.push(curr);
        }
        
        return dummy->next;
    }
};