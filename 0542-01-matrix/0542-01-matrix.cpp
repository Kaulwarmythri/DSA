class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!M[i][j]) q.push({i, j});
                else M[i][j] = -1;
            }
        }
        
        while(q.size()) {
            auto [r, c] = q.front(); q.pop();
            
            for(auto &dir: dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || M[nr][nc] != -1) continue;
                M[nr][nc] = M[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return M;
    }
};