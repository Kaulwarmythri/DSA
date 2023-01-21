//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/*struct Node {
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
class Solution {
public:
    Node* addOne(Node *head) {
        Node *prev = head, *curr = head;
        
        while(curr->next) {
            if(curr->data != 9) prev = curr;
            curr = curr->next;
        }
        
        if(curr->data == 9) {
            if(prev->data == 9 && prev == head) {
                Node *temp = new Node(1);
                temp->next = head;
                head = temp;
                curr = prev;
            } else {
                curr = prev;
                curr->data += 1;
                curr = curr->next;
            }
            
            while(curr) {
                curr->data = 0;
                curr = curr->next;
            }
        } else {
            curr->data += 1;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends