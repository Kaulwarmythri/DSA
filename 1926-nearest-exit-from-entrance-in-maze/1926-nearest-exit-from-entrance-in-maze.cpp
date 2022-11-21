class Solution {
public:
    int nearestExit(vector<vector<char>>& M, vector<int>& E) {
        int m = M.size(), n = M[0].size(), ans = 1;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int, int>> q; q.push({E[0], E[1]}); M[E[0]][E[1]] = '+';
        
        while(q.size()) {
            int s = q.size(); 
            
            while(s--) {
                auto [x, y] = q.front(); q.pop();
                
                for(int k=0; k<4; k++) {
                    int i = x+dir[k][0], j = y+dir[k][1];
                    if(i < 0 || j < 0 || i >= m || j >= n || M[i][j] == '+')
                        continue;
                    if(i == 0 || j == 0 || i == m-1 || j == n-1)
                        return ans;
                    
                    M[i][j] = '+';
                    q.push({i, j});
                }
            }
            ans++;
        }
        return -1;
    }
};

