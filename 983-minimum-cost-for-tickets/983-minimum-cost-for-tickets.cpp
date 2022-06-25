class Solution {
    int n;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        
        vector<int> dp(n+1, -1);
        dp[n] = 0;
        
        return solve(days, costs, 0, dp);
    }
    
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int> &dp) {
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        int i;
        int day_1 = costs[0] + solve(days, costs, idx+1, dp);
        
        for(i=idx; i<n && days[i] < days[idx]+7; i++);
        
        int day_7 = costs[1] + solve(days, costs, i, dp);
        
        for(i=idx; i<n && days[i] < days[idx]+30; i++);
            
        int day_30 = costs[2] + solve(days, costs, i, dp);
        
        return dp[idx] = min({day_1, day_7, day_30});
            
    }
};

