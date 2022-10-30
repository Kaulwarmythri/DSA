class Solution {
    int m, n;
public:
    int shortestPath(vector<vector<int>>& G, int k) {
        m = G.size(), n = G[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        
        queue<vector<int>> q; q.push({0, 0, 0, k});
        
        while(q.size()) {
            auto c = q.front(); q.pop();
            auto x = c[0], y = c[1];
            
            if(x < 0 || y < 0 || x >= m || y >= n) continue;
            
            if(x == m-1 && y == n-1) return c[2];
            
            if(G[x][y] == 1) {
                if(c[3] > 0) c[3]--;
                else continue;
            }
            
            if(vis[x][y] != -1 && vis[x][y] >= c[3])
                continue;
            
            vis[x][y] = c[3];
            
            q.push({x-1, y, c[2]+1, c[3]});
            q.push({x, y-1, c[2]+1, c[3]});
            q.push({x+1, y, c[2]+1, c[3]});
            q.push({x, y+1, c[2]+1, c[3]});
        }
        return -1;
    }
};