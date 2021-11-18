class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1); 
        for (int x = 2; x <= n; ++x) 
            for (int i = 1; i <= x/2; ++i) 
                dp[x] = max(dp[x], max(i, dp[i])*max(x-i, dp[x-i])); 
        return dp[n]; 
    }
};