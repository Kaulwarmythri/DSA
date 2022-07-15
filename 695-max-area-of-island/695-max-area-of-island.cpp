class Solution {
    int maxi, m, n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxi = 0; m = grid.size(); n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                maxi = max(maxi, solve(grid, i, j));
            }
        }
        return maxi;
    }
    
    int solve(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) return 0;
        
        grid[i][j] = 0;
        return 1+ solve(grid, i-1, j) + solve(grid, i, j-1) + solve(grid, i+1, j) + solve(grid, i, j+1);
        
    }
};