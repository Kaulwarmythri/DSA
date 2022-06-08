class Solution {
    int n;
public:
    int minInsertions(string s) {
        n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        
        int llcs = lcs(s, t);
        return n - llcs;
    }
    
    int lcs(string s, string t) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 || j==0) dp[i][j] = 0;
                
                else {
                    dp[i][j] = (s[i-1] == t[j-1]) ? 1+dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};