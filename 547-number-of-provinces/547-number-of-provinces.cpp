class Solution {
    int n;
public:
    int findCircleNum(vector<vector<int>>& G) {
        n = G.size();
        int count = 0;
        vector<bool> vis(n, 0);
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                count++;
                dfs(G, vis, i);
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>> &G, vector<bool> &vis, int curr) {
        vis[curr] = true;
        
        for(int j=0; j<n; j++) {
            if(G[curr][j] && !vis[j]) {
                dfs(G, vis, j);
            }
        }
    }
};