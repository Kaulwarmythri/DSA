class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        long dp[n+1][amount+1];
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=amount;i++) dp[0][i]=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
        }
        return (dp[n][amount]==INT_MAX?-1:dp[n][amount]);
    }
};