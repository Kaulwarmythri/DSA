class Solution {
    int m, n;
public:
    int numIslands(vector<vector<char>>& G) {
        m = G.size(), n = G[0].size();
        int count = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(G[i][j] == '1') {
                    count++;
                    erase(G, i, j);
                }
            }
        }
        return count;
    }
    
    void erase(vector<vector<char>> &G, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || G[i][j] == '0') return;
        
        G[i][j] = '0';
        erase(G, i-1, j);
        erase(G, i, j-1);
        erase(G, i+1, j);
        erase(G, i, j+1);
    }
};