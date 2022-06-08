class Solution {
    int n;
public:
    int longestPalindromeSubseq(string s) {
        n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        
        return lcs(s, t);
    }
    
    int lcs(string s, string t) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 || j==0) dp[i][j] = 0;
                else {
                    dp[i][j] = (s[i-1] == t[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};