class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        
        for(int i=2; i<=n; i++) {
            dp[i] = i;
            for(int j=2; j<=i/2; j++) {
                int x = i - j;
                if(x%j == 0) {
                    dp[i] = min(dp[i], dp[j] + 1 + x/j);
                }
            }
        }
        return dp[n];
    }
};