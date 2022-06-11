class Solution {
    int ans = 0, empty = 1;
    int m, n;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int sx, sy;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
                else if(grid[i][j] == 0) empty++;
            }
        }
        
        solve(grid, sx, sy, 0);
        
        return ans;
    }
    
    void solve(vector<vector<int>> &grid, int i, int j, int count) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return;
        
        if(grid[i][j] == 2) {
            if(count == empty) {
                ans ++;
            }
            return;
        }
        
        grid[i][j] = -1;
        
        solve(grid, i-1, j, count+1);
        solve(grid, i, j-1, count+1);
        solve(grid, i+1, j, count+1);
        solve(grid, i, j+1, count+1);
        
        grid[i][j] = 0;
    }
};