// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
        int n = s.size(), l, h, gap = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(; gap<n; gap++) {
            for(l=0, h=gap; h < n; l++, h++) {
                dp[l][h] = (s[l] == s[h]) ? dp[l+1][h-1] : (min(dp[l][h-1], dp[l+1][h])+1);
            }
        }
        
        return dp[0][n-1];
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