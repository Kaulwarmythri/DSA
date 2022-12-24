class Solution {
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        dp.resize(n+1, vector<int>(2, -1));
        
        return solve(0, n, false);
    }
    
    long solve(int i, int n, bool prevGap) {
        if(i > n) return 0;
        
        if(i == n) return !prevGap;
        
        if(dp[i][prevGap] != -1) return dp[i][prevGap];
        
        if(prevGap)
            return dp[i][prevGap] = (solve(i+1, n, false) + solve(i+1, n, true)) % mod;
        
        return dp[i][prevGap] = (solve(i+1, n, false) + solve(i+2, n, false) + 2l * solve(i+2, n, true)) % mod;
        
    }
};