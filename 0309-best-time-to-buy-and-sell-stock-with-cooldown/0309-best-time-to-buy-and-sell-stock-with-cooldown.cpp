class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& P) {
        n = P.size();
        dp.resize(n+1, vector<int>(2, -1));
        
        return solve(P, 0, true);
    }
    
    int solve(vector<int> &P, int i, int can) {
        if(i >= n) return 0;
        
        if(dp[i][can] != -1) return dp[i][can];
        
        if(can) {
            int buy = solve(P, i+1, false) - P[i];
            int cooldown = solve(P, i+1, true);
            
            return dp[i][can] = max(buy, cooldown);
        } else {
            int sell = solve(P, i+2, true) + P[i];
            int cooldown = solve(P, i+1, false);
            
            return dp[i][can] = max(sell, cooldown);
        }
        
        return -1;
    }
};

