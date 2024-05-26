class Solution {
    vector<vector<vector<int>>> dp;
    int mod = 1e9 + 7;
public:
    int checkRecord(int n) {
        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return solve(0, n, 0, 0);
    }
    
    int solve(int i, int n, int a, int l) {
        if(i == n)
            return 1;
        
        if(dp[i][a][l] != -1)
            return dp[i][a][l];
        
        int cur = 0;
        if(a == 0)
            cur = (cur + solve(i+1, n, a+1, 0)) % mod;
        if(l < 2)
            cur = (cur + solve(i+1, n, a, l+1)) % mod;
        
        cur = (cur + solve(i+1, n, a, 0)) % mod;
        
        return dp[i][a][l] = cur % mod;
    }
};