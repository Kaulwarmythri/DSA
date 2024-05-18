class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = 0;
    int m, n;
public:
    int getMaximumGold(vector<vector<int>>& G) {
        m = G.size(), n = G[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(G[i][j])
                    ans = max(ans, solve(G, i, j));
            }
        }
        return ans;
    }
    
    int solve(vector<vector<int>> &G, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || !G[i][j])
            return 0;
        
        int cur = G[i][j], localMaxGold = cur;
        G[i][j] = 0;
        
        for(int k=0; k<4; k++) 
            localMaxGold = max(localMaxGold, cur + solve(G, i+dirs[k][0], j+dirs[k][1]));
        
        G[i][j] = cur;
        return localMaxGold;
    }
};