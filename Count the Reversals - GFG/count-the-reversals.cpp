//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends
int countRev (string s) {
    int n = s.size(), open = 0, close = 0;
    if(n & 1) return -1;
    
    for(int i=0; i<n; i++) {
        if(s[i] == '{') open++;
        else {
            if(open > 0) open--;
            else close++;
        }
    }
    int ans = open / 2 + close / 2;
    
    close %= 2;
    if(close) ans += 2;
    return ans;
}