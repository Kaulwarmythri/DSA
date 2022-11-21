class Solution {
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& W) {   
        int m = W.size(), n = W[0].size(), h = 1;
        
        queue<pair<int, int>> q; 
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                W[i][j] = W[i][j] == 1 ? 0 : -1;
                if(W[i][j] == 0) q.push({i, j});
            }
        }
     
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto [i, j] = q.front(); q.pop();
                for(int k=0; k<4; k++) {
                    int x = i+dir[k][0], y = j + dir[k][1];
                    if(x < 0 || y < 0 || x >= m || y >= n || W[x][y] != -1) 
                        continue;
                    W[x][y] = h;
                    q.push({x, y});
                }
            }
            h++;
        }
        return W;
    }
};