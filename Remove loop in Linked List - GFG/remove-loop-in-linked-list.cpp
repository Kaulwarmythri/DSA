//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};*/

class Solution {
    public:
    void removeLoop(Node* head) {
        Node *fast = head, *slow = head, *p, *q;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) break;
        }
        if(fast != slow) return;
        
        p = slow; int count = 1;
        while(p->next != slow) {
            p = p->next;
            count++;
        }
        p = head, q = head;
        for(int i=0; i<count; i++) q = q->next;
        while(p != q) {
            p = p->next;
            q = q->next;
        }
        while(q->next != p) q = q->next;
        q->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends