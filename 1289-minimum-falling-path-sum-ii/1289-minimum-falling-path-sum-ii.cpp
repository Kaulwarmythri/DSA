class Solution {
    int m, n;
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(m == 1) return grid[0][0];
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int ans = INT_MAX;
        
        for(int j=0; j<n; j++) {
            ans = min(ans, path(grid, 0, j, dp));
        }
        
        return ans;
    }
    
    int path(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(i == m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int col=0; col<n; col++) {
            if(col == j) continue;
            ans = min(ans, path(grid, i+1, col, dp) + grid[i][j]);
        }
        return dp[i][j] = ans;
    }
};