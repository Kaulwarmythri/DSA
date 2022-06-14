class Solution {
    int m, n;
public:
    int minDistance(string s1, string s2) {
        m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(!i || !j) dp[i][j] = 0;
                else 
                    dp[i][j] = (s1[i-1] == s2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return m - dp[m][n] + n - dp[m][n];
    }
};