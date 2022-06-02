// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int w[], int v[], int n) { 
       int dp[2][W+1];
       
       for(int i=0; i<=n; i++) {
           for(int j=0; j<=W; j++) {
               if(i==0 || j==0) dp[i%2][j] = 0;
               else if(w[i-1] <= j) {
                   dp[i%2][j] = max(v[i-1] + dp[(i-1)%2][j-w[i-1]], dp[(i-1)%2][j]);
               } else dp[i%2][j] = dp[(i-1)%2][j];
           }
       }
       return dp[n%2][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends