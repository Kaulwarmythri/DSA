// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int n) {
        int curr_reach=0, max_reach=0;
        
        for(int i=0; i<n-1; i++) {
            if(i > curr_reach) return 0;
            max_reach = A[i]+i;
            curr_reach = max(curr_reach, max_reach);
        }
        return curr_reach >= n-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends