//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int transform (string A, string B) {
        int m = A.size(), n = B.size(), ans = 0;
        vector<int> count(256, 0);
        
        for(int i=0; i<m; i++) count[A[i]]++;
        
        for(int i=0; i<n; i++) count[B[i]]--;
        
        for(int i=0; i<256; i++) if(count[i]) return -1;
        
        for(int i=m-1, j=n-1; i>=0; j>=0) {
            while(i >= 0 && A[i] != B[j]) i--, ans++; 
            
            if(i >= 0) i--, j--;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends