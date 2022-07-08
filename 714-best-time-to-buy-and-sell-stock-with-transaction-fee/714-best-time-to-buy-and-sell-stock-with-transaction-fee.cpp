class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return solve(prices, 0, fee, true);
    }
    
    int solve(vector<int> &prices, int i, int fee, bool can) {
        if(i >= n) return 0;
        
        if(dp[i][can] != -1) return dp[i][can];
        
        int idle = solve(prices, i+1, fee, can);
        if(can) {
            int buy = solve(prices, i+1, fee, false) - prices[i];
            return dp[i][can] = max(idle, buy);
        } else {
            int sell = solve(prices, i+1, fee, true) + prices[i] - fee;
            return dp[i][can] = max(idle, sell);
        }
        return 0;
    }
};