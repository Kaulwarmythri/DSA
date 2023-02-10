class Solution {
    pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int maxDistance(vector<vector<int>>& G) {
        int n = G.size(), max_dis = 0;
        
        queue<pair<int, int>> q; 
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(G[i][j]) q.push({i, j});
            }
        }
        
        while(q.size()) {
            pair<int, int> cur = q.front(); q.pop();
            
            for(int k=0; k<4; k++) {
                int x = cur.first + dirs[k].first, y = cur.second + dirs[k].second;
                if(x >= 0 && x < n && y >= 0 && y < n && G[x][y] == 0) {
                    q.push({x, y});
                    G[x][y] = G[cur.first][cur.second] + 1;
                    max_dis = max(G[x][y], max_dis);
                }
            }
        }
        return max_dis - 1;
    }
};