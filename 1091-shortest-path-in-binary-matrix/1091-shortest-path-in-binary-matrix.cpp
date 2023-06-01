class Solution {
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int m, n;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& G) {
        m = G.size(), n = G[0].size();
        
        if(G[0][0] || G[m-1][n-1]) return -1;
        
        queue<pair<int, int>> q; q.push({0, 0});
        G[0][0] = 1;
        
        while(!q.empty() && !G[m-1][n-1]) {
            auto curr = q.front(); q.pop();
            
            for(int k=0; k<8; k++) {
                int x = curr.first + dirs[k][0], y = curr.second + dirs[k][1];
                
                if(valid(G, x, y)) {
                    G[x][y] = G[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            } 
        }
        return G[m-1][n-1] ? G[m-1][n-1] : -1;
    }
    
    bool valid(vector<vector<int>> &G, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n && G[x][y] == 0;
    }
};