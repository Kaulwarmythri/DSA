class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, h = cells.size(), ans = 0;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (canWalk(cells, row, col, mid)) {
                ans = mid;
                l = mid + 1; 
            } else 
                h = mid - 1;
        }
        return ans;
    }
    
    bool canWalk(vector<vector<int>>& cells, int row, int col, int mid) {
        vector<vector<bool>> G(row, vector<bool>(col, 0)); 
        
        for (int day = 0; day < mid; day++) 
            G[cells[day][0]-1][cells[day][1]-1] = 1;
        queue<pair<int, int>> q;
        
        for (int c = 0; c < col; ++c) {
            if (G[0][c] == 0) { 
                q.push({0, c});
                G[0][c] = 1; 
            }
        }
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            
            if (r == row - 1) 
                return true;
            
            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k][0], nc = c + dirs[k][1];
                if (nr < 0 || nr == row || nc < 0 || nc == col || G[nr][nc] == 1) continue;
                G[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }
};