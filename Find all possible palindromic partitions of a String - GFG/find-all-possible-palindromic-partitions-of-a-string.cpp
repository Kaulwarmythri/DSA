// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    vector<string> buff;
    vector<vector<string>> ans;
    vector<vector<int>> dp;
    int n;
    
public:
    vector<vector<string>> allPalindromicPerms(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n, -1));
        
        solve(s, 0, buff, ans);
        return ans;
    }
    
    void solve(string s, int idx, vector<string> &buff, vector<vector<string>> &ans) {
        if(idx == n) {
            ans.push_back(buff);
            return;
        }
        
        for(int j=idx; j<n; j++) {
            if(check(s, idx, j)) {
                buff.push_back(s.substr(idx, j-idx+1));
                solve(s, j+1, buff, ans);
                buff.pop_back();
            }
        }
        
    }
    
    bool check(string str, int s, int e) {
        if(dp[s][e] != -1) return dp[s][e];
        
        while(s < e) {
            if(str[s] != str[e]) return dp[s][e] = 0; 
            s++; e--;
        }
        return dp[s][e] = 1;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends