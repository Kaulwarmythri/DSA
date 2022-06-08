// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        string ans = "";
        ans += s[0];
        
        for(int i=0; i<n; i++) dp[i][i] = true;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(s[i] == s[j]) {
                    if(i-j==1 || dp[i-1][j+1]) {
                        dp[i][j] = true;
                        if(i-j+1 > ans.size()) ans = s.substr(j, i-j+1);
                    }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends