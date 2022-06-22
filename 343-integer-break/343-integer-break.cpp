class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 6;
        
        vector<int> dp(n+1, 0);
        
        dp[2] = 1; dp[3] = 2; dp[4] = 4; dp[5] = 6; 
        
        for(int i=6; i<=n; i++) {
            dp[i] = max(dp[i-3]*3, (i-3)*3);
        }
        
        return dp[n];
    }
};