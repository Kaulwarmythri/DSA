class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0, repeat = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    count++;
                    if(i > 0 && grid[i-1][j]) repeat++;
                    if(j > 0 && grid[i][j-1]) repeat++;
                }
            }
        }
        return 4 * count - 2 * repeat;
    }
};