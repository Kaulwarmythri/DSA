class Solution {
    int m, n, ans = 0, empty = 1;
public:
    int uniquePathsIII(vector<vector<int>>& G) {
        m = G.size(), n = G[0].size();
        int sx, sy;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(G[i][j] == 1) 
                    sx = i, sy = j;
                else if(G[i][j] == 0)
                    empty++;
            }
        }
        solve(G, sx, sy, 0);
        return ans;
    }
    
    void solve(vector<vector<int>> &G, int i, int j, int count) {
        if(i < 0 || j < 0 || i >= m || j >= n || G[i][j] == -1) return;
        
        if(G[i][j] == 2) {
            if(count == empty) {
                ans++;
                return;
            }
        }
        
        int temp = G[i][j];
        G[i][j] = -1;
        
        solve(G, i-1, j, count+1);
        solve(G, i, j-1, count+1);
        solve(G, i+1, j, count+1);
        solve(G, i, j+1, count+1);
        
        G[i][j] = temp;
    }
};