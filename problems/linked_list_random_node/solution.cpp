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
    ListNode *head;
public:
    Solution(ListNode* head) : head(head) {}
    
    int getRandom() {
        int ans = 0, n = 0; 
        for (ListNode* node = head; node; ++n, node = node->next) 
            if (rand() % (n+1) == 0) ans = node->val; 
        return ans; 
    }
};
/*
class Solution {
    ListNode* head; 
public:
    Solution(ListNode* head) : head(head) {}
    
    int getRandom() {
        int ans = 0, n = 0; 
        for (ListNode* node = head; node; ++n, node = node->next) 
            if (rand() % (n+1) == 0) ans = node->val; 
        return ans; 
    }
};
*/


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */