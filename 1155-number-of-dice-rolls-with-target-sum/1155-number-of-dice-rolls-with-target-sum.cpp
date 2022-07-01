class Solution {
    int mod = pow(10, 9) + 7;
public:
    int numRollsToTarget(int n, int k, int X) {
        vector<vector<int>> dp(n+1, vector<int>(X+1, 0));
        
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=X; j++) {
                for(int m=1; m<=k && m<=j; m++) {
                    dp[i][j] = (dp[i][j] % mod + dp[i-1][j - m] % mod) % mod;
                }
            }
        }
        return dp[n][X] % mod;
    }
};

