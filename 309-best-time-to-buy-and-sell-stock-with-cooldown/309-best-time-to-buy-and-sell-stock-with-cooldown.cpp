class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return solve(prices, 0, true);
    }
    
    int solve(vector<int> &prices, int idx, bool buying) {
        if(idx >= n) return 0;
        
        if(dp[idx][buying] != -1) return dp[idx][buying];
        
        int cooldown = solve(prices, idx+1, buying);
        if(buying) {
            int buy = solve(prices, idx+1, !buying) - prices[idx];
            
            return dp[idx][buying] = max(buy, cooldown);
        } else {
            int sell = solve(prices, idx+2, !buying) + prices[idx];
            
            return dp[idx][buying] = max(sell, cooldown);
        }
        return -1;
    }
};