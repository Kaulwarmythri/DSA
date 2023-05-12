class Solution {
    int n;
    vector<long long> dp;
public:
    long long mostPoints(vector<vector<int>>& Q) {
        n = Q.size();
        dp.resize(n+1, -1);
        
        return solve(Q, 0);
    }
    
    long long solve(vector<vector<int>> &Q, int i) {
        if(i >= n) return 0;
        
        if(dp[i] != -1) return  dp[i];
        
        long long inc = Q[i][0] + solve(Q, i+Q[i][1]+1);
        long long exc = solve(Q, i+1);
        
        return dp[i] = max(inc, exc);
    }
};