class Solution {
    int m, n, ans = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    erase(grid, i, j);
                }
            }
        }
        return ans;
    }
    
    void erase(vector<vector<char>> &grid, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') return;
        
        grid[x][y] = '0';
        
        erase(grid, x-1, y);
        erase(grid, x+1, y);
        erase(grid, x, y-1);
        erase(grid, x, y+1);
    }
};