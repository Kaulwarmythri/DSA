//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
/*class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};*/

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int X) {
        vector<pair<int, int>> ans;
        
        Node *first = head, *sec = head;
        while(sec->next) 
            sec = sec->next;
        while(first != sec && sec->next != first) {
            if(first->data + sec->data == X) {
                ans.push_back({first->data, sec->data});
                first = first->next;
                sec = sec->prev;
            } else if(first->data + sec->data < X) {
                first = first->next;
            } else 
                sec = sec->prev;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends