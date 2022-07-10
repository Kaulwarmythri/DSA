// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = pow(10, 9) + 7;
public:
    int nCr(int n, int r){
        if(r > n) return 0;
        // nCr = (n-1)C(r-1) + (n-1)Cr
        vector<vector<int>> dp(n+1, vector<int>(r+1));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=min(i, r); j++) {
                if(j == 0 || j == i) dp[i][j] = 1;
                else {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
            }
        }
        return dp[n][r] % mod;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends