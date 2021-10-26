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
    ListNode* t1=l1;
    ListNode* t2=l2;
    int len1=0,len2=0;
    while(t1!=NULL){
        t1=t1->next;
        len1++;
    }
    while(t2!=NULL){
        t2=t2->next;
        len2++;
    }
    if(len1!=len2){
        if(len1 < len2){
            int temp=len2-len1;
            for(int i=0;i<temp;++i){
                ListNode* t=new ListNode(0);
                t->next=l1;
                l1=t;
            }
        } else{
            int temp=len1-len2;
            for(int i=0;i<temp;++i){
                ListNode* t=new ListNode(0);
                t->next=l2;
                l2=t;
            }
        }
    }
   int remain= solve(l1,l2);
    if(remain > 0){
        ListNode* l=new ListNode(remain);
        l->next=l2;
        l2=l;
    }
    return l2;
}

int solve(ListNode* l1, ListNode* l2){
    if(!l1 && !l2) return 0;
   int carry=solve(l1->next,l2->next);
    int value=l1->val + l2->val + carry;
    l2->val=value%10;
    return value/10;
    
}
};