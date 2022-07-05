class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); 
        
        for(int gap=1; gap<=n; gap++) {
            for(int i=0; i+gap-1<=n; i++) {
                
                if(gap == 1) dp[i][i+gap-1] = 0;
                
                else if(gap == 2) dp[i][i+gap-1] = i;
                
                else {
                    int ans = INT_MAX;
                    
                    for(int k=i+1; k < i+gap-1; k++) {
                        ans = min(ans, k + max(dp[i][k-1], dp[k+1][i+gap-1]));
                    }
                    dp[i][i+gap-1] = ans;
                    
                }
            }
        }
        return dp[1][n];
    }
};