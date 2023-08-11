class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+1, n+1);
        
        dp[0] = 0;
        
        for(int i=1; i<=n; i++) {
            for(auto &c: coins) {
                if(c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }
};