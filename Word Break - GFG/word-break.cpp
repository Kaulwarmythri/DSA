//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int n;
    vector<int> dp;
public:
    int wordBreak(string A, vector<string> &B) {
        n = A.size();
        set<string> s(B.begin(), B.end());
        dp.resize(n+1, -1);
        dp[n] = 1;
        return solve(A, s, 0);
    }
    
    bool solve(string A, set<string> s, int i) {
        if(i == n) return true;
        
        if(dp[i] != -1) return dp[i];
        
        for(int j=i; j<n; j++) {
            if(s.count(A.substr(i, j-i+1)) && solve(A, s, j+1))
            return dp[i] = true;
        }
        return dp[i] = false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends