class Solution {
public:
    int longestCommonSubsequence(string S, string T) {
        int m = S.size(), n = T.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(!i || !j) dp[i][j] = 0;
                else {
                    if(S[i-1] == T[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};