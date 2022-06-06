class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(amount+1));
        
        for(int i=0; i<n; i++) dp[i][0] = 1;
        
        for(int i=0; i<n; i++) {
            for(int amt=1; amt <= amount; amt++) {
                //excluding
                int x = (i >= 1) ? dp[i-1][amt] : 0;
                //including
                int y = (amt - coins[i] >= 0) ?  dp[i][amt-coins[i]] : 0;
                
                dp[i][amt] = x+y;
            }
        }
        return dp[n-1][amount];
    }
};