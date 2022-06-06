// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return solve(price, n-1, n, dp);
    }
    
    int solve(int price[], int idx, int n, vector<vector<int>> &dp) {
        if(idx == 0) return price[0]*n;
        
        if(dp[idx][n] != -1) return dp[idx][n];
        
        int x,y=INT_MIN;
        x = solve(price, idx-1, n, dp);
        
        if(idx <= n) y = price[idx] + solve(price, idx, n-idx-1, dp);
        
        return dp[idx][n] = max(x, y);
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends