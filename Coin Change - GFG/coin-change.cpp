// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {
        vector<vector<long long int>> dp(m, vector<long long int>(n+1));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
 
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                long long int x = (j-S[i] >= 0) ? dp[i][j-S[i]] : 0;
                
                long long int y = (i >= 1) ? dp[i-1][j] : 0;

                dp[i][j] = x + y;
            }
        }
        return dp[m-1][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends