// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int n;
  public:
    int countMin(string s){
        n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        
        int llcs = lcs(s, t);
        return n - llcs;
    }
    
    int lcs(string s, string t) {
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 || j==0) dp[i][j] = 0;
                
                else dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + 1 
                            : max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
    
    
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends