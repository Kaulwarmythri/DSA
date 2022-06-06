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
    
    int solve(int price[], int index, int n, vector<vector<int>> &dp) {
        if (index == 0) return n * price[0];

    if (dp[index][n] != -1)
        return dp[index][n];
    int notCut = solve(price, index - 1, n,dp);
    int cut = INT_MIN;
    int rod_length = index + 1;
 
    if (rod_length <= n)
        cut = price[index]
              + solve(price, index, n - rod_length,dp);
 
    return dp[index][n]=max(notCut, cut);
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