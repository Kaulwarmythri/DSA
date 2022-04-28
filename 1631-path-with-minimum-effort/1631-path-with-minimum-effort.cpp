class Solution {
    int m, n;
    int dirX[4] = {0, 0, -1, 1}, dirY[4] = {-1, 1, 0, 0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        
        int l = 0, h = 1e6;
        
        while(l < h) {
            int mid = (l+h)>>1;
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            
            if(isPossible(heights, vis, mid, 0, 0)) h = mid;
            else l = mid+1;
        }
        return l;
    }
    
    bool isPossible(vector<vector<int>>&X, vector<vector<bool>>&vis, int mid, int x, int y){
        if(x == m-1 && y == n-1) return true;
        
        vis[x][y] = true;
        
        for(int i=0; i<4; i++) {
            int newX = x + dirX[i], newY = y + dirY[i];
            
            if(newX >= 0 && newX < m && newY >= 0 && newY < n && !vis[newX][newY]) {
                if(abs(X[newX][newY] - X[x][y]) <= mid) {
                    
                    if(isPossible(X, vis, mid, newX, newY)) return true;
                }
            }
        }
        return false;
            
    }
};