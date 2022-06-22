// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) {
        int m = A.size(), n = B.size(), p = C.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(!i && !j) dp[i][j] = true;
                else {
                    if(!i) dp[i][j] = dp[i][j-1] && B[j-1] == C[i+j-1];
                    else if(!j) dp[i][j] = dp[i-1][j] && A[i-1] == C[i+j-1];
                    else {
                        dp[i][j] = (dp[i-1][j] && A[i-1] == C[i+j-1]) 
                        || (dp[i][j-1] && B[j-1] == C[i+j-1]);
                    }
                }
            }
        }
        return dp[m][n];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends