//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
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


// } Driver Code Ends
/*struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
}*/
class Solution {
public:
    int findFirstNode(Node* head) {
        Node *fast = head, *slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) break;
        }
        if(fast != slow) return -1;
        
        int count = 1;
        while(fast->next != slow) {
            fast = fast->next;
            count++;
        }
        fast = head; slow = head;
        for(int i=0; i<count; i++) {
            fast = fast->next;
        }
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast->data;
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
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends