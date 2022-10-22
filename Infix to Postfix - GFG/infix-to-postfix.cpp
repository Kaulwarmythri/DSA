//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string infixToPostfix(string str) {
        int n = str.size();
        string ans = "";
        stack<char> s;
        
        for(int i=0; i<n; i++) {
            char c = str[i];
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
                ans += c;
            else if(c == '(') 
                s.push(c);
            else if(c == ')') {
                while(s.top() != '(') {
                    ans += s.top(); s.pop();
                }
                s.pop();
            } else {
                while(!s.empty() && prec(c) <= prec(s.top())) {
                    ans += s.top(); s.pop();
                }
                s.push(c);
            }
        }
        while(!s.empty()) {
            ans += s.top(); s.pop();
        }
        return ans;
    }
    
    int prec(char c) {
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if( c== '+' || c == '-') return 1;
        else return -1;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends