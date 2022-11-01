class Solution {
    int m, n;
    vector<int> ans;
public:
    vector<int> findBall(vector<vector<int>>& G) {
        m = G.size(), n = G[0].size();
        ans.resize(n, 0);
        
        for(int i=0; i<n; i++) 
            ans[i] = dfs(G, 0, i);
        
        return ans;
    }
    
    int dfs(vector<vector<int>> &G, int row, int col) {
        if(row == m) {
            return col;
        }
        
        if(isvalid(row, col)) {
            if(G[row][col] == 1) {
                if(isvalid(row, col+1) && G[row][col+1] == 1) 
                    return dfs(G, row+1, col+1);
            } else {
                if(isvalid(row, col-1) && G[row][col-1] == -1)
                    return dfs(G, row+1, col-1);
            }
        }
        return -1;
    }
    
    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
};