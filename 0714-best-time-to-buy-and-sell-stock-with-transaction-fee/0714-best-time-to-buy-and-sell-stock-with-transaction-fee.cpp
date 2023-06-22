class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& P, int fee) {
        n = P.size();
        dp.resize(n+1, vector<int>(2, -1));
        
        return solve(P, fee, 0, true);
    }
    
    int solve(vector<int> &P, int fee, int i, bool can) {
        if(i >= n) return 0;
        
        if(dp[i][can] != -1) return dp[i][can];
        
        if(can) {
            int buy = solve(P, fee, i+1, false) - P[i];
            int notbuy = solve(P, fee, i+1, true);
            return dp[i][can] = max(buy, notbuy);
        } else {
            int sell = solve(P, fee, i+1, true) + P[i] - fee;
            int notsell = solve(P, fee, i+1, false);
            return dp[i][can] = max(sell, notsell);
        }
        return 0;
    }
};