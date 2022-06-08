class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int gap=1; gap<n; gap++) {
            for(int i=0; i<n-gap; i++) {
                int j = i+gap;
                
                if(j-i == 1) dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                else {
                    dp[i][j] = (s[i] == s[j]) 
                        ? 2 + dp[i+1][j-1] : max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};