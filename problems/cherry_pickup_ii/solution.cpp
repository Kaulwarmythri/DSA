class Solution {
    vector<vector<vector<int>>> dp;
    int m, n;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(grid, 0, 0, n-1);
    }
    
    int solve(vector<vector<int>> &grid, int r, int c1, int c2){
        if(r >= m || c1 >= n || c2 >= n || c1 < 0 || c2 < 0) return 0;
        
        if(r == m) return grid[r][c1];
        
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int ans = 0, dir[3] = {-1, 0, 1}, total = INT_MIN;
        
        ans = grid[r][c1];
        if(c1 != c2) ans += grid[r][c2];
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                total = max(total, solve(grid, r+1, c1+dir[i], c2+dir[j]));
            }
        }
        ans += total;
        return dp[r][c1][c2] = ans;
        
    }
};
