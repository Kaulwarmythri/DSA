// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        vector<vector<int>> cp(n, vector<int>(n));
        
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
            cp[i][i] = 0;
        }
        
        for(int gap=1; gap<n; gap++) {
            for(int i=0, j=gap; j<n; i++, j++) {
                if(j == i+1) dp[i][j] = (s[i] == s[j]);
                
                else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                
                if(dp[i][j]) cp[i][j] = 0;
                
                else {
                    cp[i][j] = INT_MAX;
                    
                    for(int k=i; k<j; k++) {
                        cp[i][j] = min(cp[i][j], cp[i][k] + 1 + cp[k+1][j]);
                    }
                }
            }
        }
        return cp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends