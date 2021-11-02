class Solution {
public:
    int res=0, empty=1;
    void dfs(vector<vector<int>> &grid, int i, int j, int count){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-1) return;
        
        if(grid[i][j]==2){
            if(count==empty) res++;
            return;
        }
        grid[i][j]=-1;
        
        dfs(grid, i+1, j, count+1);
        dfs(grid, i-1, j, count+1);
        dfs(grid, i, j+1, count+1);
        dfs(grid, i, j-1, count+1);
        
        grid[i][j]=0;
            
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int s_x, s_y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    s_x=i; 
                    s_y=j;
                }
                else if(grid[i][j]==0) empty++;
            }
        }
        dfs(grid, s_x, s_y, 0);
        return res;
    }
};