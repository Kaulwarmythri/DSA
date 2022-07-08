class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size(); 
        dp.resize(n+1, vector<int>(2, -1));
        
        return solve(prices, 0, true);
    }
    
    int solve(vector<int> &prices, int i, bool can) {
        if(i >= n) return 0;
        
        if(dp[i][can] != -1) return dp[i][can];
        
        if(can) {
            int buy = solve(prices, i+1, false) - prices[i];
            int cooldown = solve(prices, i+1, true);
            return dp[i][can] = max(buy, cooldown);
        } else {
            int sell = solve(prices, i+2, true) + prices[i];
            int cooldown = solve(prices, i+1, false);
            return dp[i][can] = max(sell, cooldown);
        }
        return 0;
    }
};
