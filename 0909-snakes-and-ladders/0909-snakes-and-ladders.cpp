class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& B) {
        int n = B.size(), dest = 1, moves = 0;
        
        vector<bool> vis(n * n + 1, false);
        queue<pair<int, int>> q; q.push({1, 0});
        
        while(q.size()) {
            auto [x, steps] = q.front(); q.pop();
            if(x == n * n) 
                return steps;
            
            int row, col;
            for(int i=1; i<=6 && x + i <= n * n; i++) {
                calcCoordinates(n, x + i, row, col);
                
                int dest = B[row][col] == -1 ? x + i : B[row][col];
                if(!vis[dest]) {
                    vis[dest] = true;
                    q.push({dest, steps+1});
                }
            }
        }
        return -1;
    }
    
    void calcCoordinates(int n, int x, int &row, int &col) {
        row = n - 1 - (x - 1) / n;
        col = (x - 1) % n;
        
        if(n % 2 == row % 2) 
            col = n - 1 - col;    
    }
};