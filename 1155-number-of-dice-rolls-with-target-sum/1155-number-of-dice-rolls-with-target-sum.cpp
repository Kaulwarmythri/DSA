#define M 1000000007
class Solution {
public:
    int numRollsToTarget(int n, int k, int X) {
        
        vector<vector<int>> dp(n+1, vector<int>(X+1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= X; j++) {
                for(int p = 1; p <= k && p <= j; p++) {
                    dp[i][j] += (dp[i-1][j-p]);
                    dp[i][j] %= M;
                }
            } 
        }
        return dp[n][X];
    }
};