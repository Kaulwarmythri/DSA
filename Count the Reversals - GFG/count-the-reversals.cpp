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
    int n = s.size(), temp = 0, ans = 0;
    if(n & 1) return -1;
    
    for(int i=0; i<n; i++) {
        if(s[i] == '{') temp++;
        else {
            if(temp == 0) {
                temp++;
                ans++;
            }
            else temp--;
        }
    }
    ans += temp / 2;
    return ans;
}