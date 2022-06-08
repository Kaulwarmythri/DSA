// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> ans;
public:
    vector<int> pattern(int N){
        solve(N);
        
        return ans;
    }
    
    void solve(int N) {
        if(N == 0 || N < 0) {
            ans.push_back(N);
            return;
        }
        
        ans.push_back(N);
        
        solve(N-5);
        
        ans.push_back(N);
    }
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends