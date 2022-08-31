class Solution {
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H) {
        m = H.size(), n = H[0].size();
        
        vector<vector<bool>> pacific, atlantic;
        vector<vector<int>> ans;
        
        pacific = atlantic = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            dfs(H, pacific, i, 0);
            dfs(H, atlantic, i, n-1);
        }
        
        for(int j=0; j<n; j++) {
            dfs(H, pacific, 0, j);
            dfs(H, atlantic, m-1, j);
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &H, vector<vector<bool>> &vis, int i, int j) {
        if(vis[i][j]) return;
        
        vis[i][j] = true;
        
        if(i > 0 && H[i-1][j] >= H[i][j])  
            dfs(H, vis, i-1, j);
        if(i < m-1 && H[i+1][j] >= H[i][j]) 
            dfs(H, vis, i+1, j);
        if(j > 0 && H[i][j-1] >= H[i][j]) 
            dfs(H, vis, i, j-1);
        if(j < n-1 && H[i][j+1] >= H[i][j])
            dfs(H, vis, i, j+1);
    }
};