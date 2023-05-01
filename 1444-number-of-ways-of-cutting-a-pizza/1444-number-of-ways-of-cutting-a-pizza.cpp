class Solution {
    int mod = 1e9 + 7, m, n;
    vector<vector<vector<int>>> dp;
public:
    int ways(vector<string>& P, int k) {
        m = P.size(), n = P[0].size();
        
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        
        for(int i=m-1; i>=0; i--) 
            for(int j=n-1; j>=0; j--)
                preSum[i][j] = preSum[i+1][j] + preSum[i][j+1] - preSum[i+1][j+1] + (P[i][j] == 'A');
        
        dp.resize(k, vector<vector<int>>(m, vector<int>(n, -1)));
        
        return solve(preSum, k-1, 0, 0);
    }
    
    int solve(vector<vector<int>> &P, int k, int i, int j) {
        if(P[i][j] == 0) return 0;
        
        if(k == 0) return 1;
        
        if(dp[k][i][j] != -1) return dp[k][i][j];
        
        int ans = 0;
        
        for(int ni=i+1; ni<m; ni++)
            if(P[i][j] > P[ni][j])
                ans = (ans + solve(P, k-1, ni, j)) % mod;
        for(int nj=j+1; nj<n; nj++) 
            if(P[i][j] > P[i][nj])
                ans = (ans + solve(P, k-1, i, nj)) % mod;
        
        return dp[k][i][j] = ans;
    }
};