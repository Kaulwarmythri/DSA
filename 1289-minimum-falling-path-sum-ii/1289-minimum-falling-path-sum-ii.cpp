class Solution {
    int m, n;
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        dp[0] = grid[0];
        
        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                int ans = INT_MAX;
                
                for(int k=0; k<n; k++) {
                    if(k == j) continue;
                    ans = min(ans, grid[i][j] + dp[i-1][k]);
                }
                dp[i][j] = ans;
            }
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

