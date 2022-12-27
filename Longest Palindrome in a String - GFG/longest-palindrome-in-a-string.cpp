//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n = s.size();
        string ans = ""; ans += s[0];
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(s[i] == s[j]) {
                    if(i == j+1 || dp[i-1][j+1]) {
                        dp[i][j] = 1;
                        if(ans.size() < i-j+1) ans = s.substr(j, i-j+1);
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends